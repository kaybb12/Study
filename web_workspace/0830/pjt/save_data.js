// Import the functions you need from the SDKs you need
import { initializeApp } from "https://www.gstatic.com/firebasejs/10.13.1/firebase-app.js";
import { getFirestore, 
    collection, 
    addDoc, 
    getDocs, 
    onSnapshot,
    query,
    Timestamp, 
    orderBy, 
    limit, where } from 'https://www.gstatic.com/firebasejs/10.13.1/firebase-firestore.js';
// TODO: Add SDKs for Firebase products that you want to use
// https://firebase.google.com/docs/web/setup#available-libraries

// Your web app's Firebase configuration
const firebaseConfig = {
  apiKey: "AIzaSyCwWRJgfH4U8V_6ZbaEVmrL9lFtSlqCxbw",
  authDomain: "log-project-82f53.firebaseapp.com",
  projectId: "log-project-82f53",
  storageBucket: "log-project-82f53.appspot.com",
  messagingSenderId: "176891778891",
  appId: "1:176891778891:web:3e72540698922d57787ace"
};

// Firebase 초기화
const app = initializeApp(firebaseConfig);
const db = getFirestore(app);

// 문자열에서 시간, hostname, log_level, log message 파싱
const parseLogEntry = (filename, line) => {
    const parts = line.split(' ');
        if (parts.length < 6) {
        return null;
    }
    const temp = `${parts[0]} ${parts[1]} ${parts[2]}`;
    const Time = Timestamp.fromDate(new Date(temp));

    return {
        filename: filename,
        timestamp: Time,
        hostname: parts[3],
        log_level: parts[5].replace(':', ''),
        message: parts.slice(6).join(' ')
    };
};

const formatFirestoreTimestamp = (timestamp) => {
    // Firestore Timestamp를 JavaScript Date 객체로 변환
    const date = new Date(timestamp.seconds * 1000); // 초를 밀리초로 변환

    // 날짜와 시간 포맷을 설정
    const year = date.getFullYear();
    const month = (date.getMonth() + 1).toString().padStart(2, '0'); // 월은 0부터 시작하므로 +1
    const day = date.getDate().toString().padStart(2, '0');
    const hours = date.getHours().toString().padStart(2, '0');
    const minutes = date.getMinutes().toString().padStart(2, '0');
    const seconds = date.getSeconds().toString().padStart(2, '0');

    return `${year}-${month}-${day} ${hours}:${minutes}:${seconds}`;
};

// addDoc 함수를 이용하여 firestore 에 저장
const saveLogToFirestore = async (log) => {
    try {
        const docRef = await addDoc(collection(db, 'kernel_logs'), log);
        console.log('Log entry added with ID: ', docRef.id);
    } catch (error) {
        console.error('Error adding log entry: ', error);
    }
};

const handleFileUpload = async (event) => {
    const file = event.target.files[0];
    const text = await file.text();
    const lines = text.split('\n');
    // 파일에서 로그 파싱
    const logs = lines.map(line => parseLogEntry(file.name, line)).filter(log => log !== null);
    for (const log of logs) {
        // firestore 에 저장
        await saveLogToFirestore(log);
    }
    console.log('All log entries have been uploaded.');
    alert('저장이 완료되었습니다.')
};
   
// 파일이 선택되었을 때의 이벤트 핸들러 추가
   
document.querySelector('#saveButton').addEventListener('change', handleFileUpload);  
const kernelLogsContainer = document.querySelector('.kernelLogs');

// 화면이 처음 로드될 때 데이터를 가져오는 함수
const loadAllLogs = async () => {
    const q = query(collection(db, 'kernel_logs'), orderBy('timestamp'));
    const querySnapshot = await getDocs(q);
    kernelLogsContainer.innerHTML = ''; // 기존 로그 초기화
            querySnapshot.forEach((doc) => {
                const log = doc.data();
                const filenameElement = document.createElement('div');
                filenameElement.classList.add('log-entry', 'filename');
                filenameElement.textContent = `${log.filename}`
                const logElement = document.createElement('div');
                logElement.classList.add('log-entry', 'log');
                const logLevelElement = document.createElement('span');
                logLevelElement.classList.add(log.log_level.toLowerCase());
                logLevelElement.textContent = `${log.log_level}: ${log.message}`;
                const nowtime = formatFirestoreTimestamp(log.timestamp);
                logElement.appendChild(document.createTextNode(`[ ${nowtime} ] ${log.hostname} kernel: `));
                logElement.appendChild(logLevelElement);
                kernelLogsContainer.appendChild(filenameElement);
                kernelLogsContainer.appendChild(logElement);
        });
};
 
await loadAllLogs();



// 실시간 업데이트 리스너 설정
const subscribeToRealTimeUpdates = () => {
    const q = query(collection(db, 'kernel_logs'), orderBy('timestamp'));
    const unsubscribe = onSnapshot(q, (snapshot) => {
        kernelLogsContainer.innerHTML = ''; // 기존 로그 초기화
        snapshot.forEach((doc) => {
            const log = doc.data();
            const filenameElement = document.createElement('div');
            filenameElement.classList.add('log-entry', 'filename');
            filenameElement.textContent = `${log.filename}`
            const logElement = document.createElement('div');
            logElement.classList.add('log-entry', 'log');
            const logLevelElement = document.createElement('span');
            logLevelElement.classList.add(log.log_level.toLowerCase());
            logLevelElement.textContent = `${log.log_level}: ${log.message}`;
            const nowtime = formatFirestoreTimestamp(log.timestamp);
            logElement.appendChild(document.createTextNode(`[ ${nowtime} ] ${log.hostname} kernel: `));
            logElement.appendChild(logLevelElement);
            kernelLogsContainer.appendChild(filenameElement);
            kernelLogsContainer.appendChild(logElement);
        });
    });
};

subscribeToRealTimeUpdates();

// 최근 10개의 로그를 가져오는 함수
const loadRecentLogs = async () => {
    const q = query(
        collection(db, 'kernel_logs'), 
        orderBy('timestamp', 'desc'), 
        limit(10));
    const querySnapshot = await getDocs(q);
    kernelLogsContainer.innerHTML = ''; // 기존 로그 초기화
    
    querySnapshot.forEach((doc) => {
            const log = doc.data();
            const filenameElement = document.createElement('div');
            filenameElement.classList.add('log-entry', 'filename');
            filenameElement.textContent = `${log.filename}`
            const logElement = document.createElement('div');
            logElement.classList.add('log-entry', 'log');
            const logLevelElement = document.createElement('span');
            logLevelElement.classList.add(log.log_level.toLowerCase());
            logLevelElement.textContent = `${log.log_level}: ${log.message}`;
            const nowtime = formatFirestoreTimestamp(log.timestamp);
            logElement.appendChild(document.createTextNode(`[ ${nowtime} ] ${log.hostname} kernel: `));
            logElement.appendChild(logLevelElement);
            kernelLogsContainer.appendChild(filenameElement);
            kernelLogsContainer.appendChild(logElement);
        });
};

// 최근 10개 로그 버튼 클릭 이벤트 핸들러 추가
document.querySelector('#recentLogsButton').addEventListener('click', async () => {
    await loadRecentLogs();
});
   // 전체 로그 데이터를 가져올 수 있도록 이벤트 핸들러 추가
document.querySelector('#allLogsButton').addEventListener('click', async () => {
    await loadAllLogs();
});

// 특정 시간대의 로그를 가져오는 함수
const getLogsByTimeRange = async (startTime, endTime) => {
    console.log(startTime);
    console.log(endTime);

    const q = query(
        collection(db, 'kernel_logs'),
        where('timestamp', '>=', startTime),
        where('timestamp', '<=', endTime),
        orderBy('timestamp', 'desc')
    );

    console.log(q);

    try {
        const querySnapshot = await getDocs(q);

        kernelLogsContainer.innerHTML = ''; // Clear existing logs

        querySnapshot.forEach((doc) => {
            const log = doc.data();
            const filenameElement = document.createElement('div');
            filenameElement.classList.add('log-entry', 'filename');
            filenameElement.textContent = `${log.filename}`
            const logElement = document.createElement('div');
            logElement.classList.add('log-entry', 'log');
            const logLevelElement = document.createElement('span');
            logLevelElement.classList.add(log.log_level.toLowerCase());
            logLevelElement.textContent = `${log.log_level}: ${log.message}`;
            const nowtime = formatFirestoreTimestamp(log.timestamp);
            logElement.appendChild(document.createTextNode(`[ ${nowtime} ] ${log.hostname} kernel: `));
            logElement.appendChild(logLevelElement);
            kernelLogsContainer.appendChild(filenameElement);
            kernelLogsContainer.appendChild(logElement);
        });
    } catch (error) {
        console.error('Error fetching logs:', error);
    }
};

const parseDateString = (dateString) => {
    // 12시간 형식의 시간 문자열을 24시간 형식으로 변환
    const [datePart, timePart, period] = dateString.split(' ');
    const [year, month, day] = datePart.split('-').map(Number);
    let [hour, minute] = timePart.split(':').map(Number);

    // 오후일 경우 12시간 더하기 (오후 12시는 12:00로 처리)
    if (period === '오후' && hour !== 12) {
        hour += 12;
    }
    // 오전일 경우 12시를 0시로 변환
    if (period === '오전' && hour === 12) {
        hour = 0;
    }

    // JavaScript Date 객체 생성 (월은 0부터 시작하므로 -1)
    const date = new Date(year, month - 1, day, hour, minute);

    return date;
};

const convertToFirestoreTimestamp = (dateString) => {
    const date = parseDateString(dateString);
    return Timestamp.fromDate(date);
};

// 시간대 선택 UI 생성 및 이벤트 처리
const createTimeRangeSelector = () => {
    const controls = document.querySelector('#controls');
    const timeRangeForm = document.createElement('form');
    timeRangeForm.innerHTML = `
        <input type="datetime-local" id="startTime" required>
        <input type="datetime-local" id="endTime" required>
        <button type="submit">시간대 조회</button>
    `;
    controls.appendChild(timeRangeForm);

    timeRangeForm.addEventListener('submit', async (e) => {
        e.preventDefault();
        const startTime = document.querySelector('#startTime').value;
        const endTime = document.querySelector('#endTime').value;
        
        // 'datetime-local' 입력 값을 Date 객체로 변환
        const formattedStartTime = new Date(startTime);
        const formattedEndTime = new Date(endTime);

        // Firestore Timestamp 객체로 변환
        const startTimestamp = Timestamp.fromDate(formattedStartTime);
        const endTimestamp = Timestamp.fromDate(formattedEndTime);

        console.log(startTimestamp); // 디버깅용 출력
        console.log(endTimestamp); // 디버깅용 출력
        
        // 로그를 시간대에 따라 조회
        await getLogsByTimeRange(startTimestamp, endTimestamp);
    });
};

createTimeRangeSelector();