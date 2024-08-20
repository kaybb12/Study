// 시간을 표시하는 함수를 만든다.
function updateTime(){
  const now = new Date();
  let hour = now.getHours();
  const minutes = String(now.getMinutes()).padStart(2, '0');
  const ampm = hour > 12 ? "PM" : "AM";
  hour = hour % 12; // 시간을 12시간으로 표시
  hour = hour ? hour : 12;  // 0시를 12시로 바꿔주는 작업 
  const currentTime = `${hour}:${minutes} ${ampm}`;
  const currentTimeTag = document.querySelector("#current-time");
  currentTimeTag.textContent = currentTime;
}

updateTime();
setInterval(updateTime, 1000);

let language = 'korean'

function conversion() {
  const tiles = {
    "네비게이션": 'Navigation',
    "날씨": 'Weather',
    "전화": 'Phone',
    "비디오": 'Video',
    "사진": 'Photo',
    "음악 추천": 'Music',
    "한/영": 'Language',
    "설정": 'Settings',
    "Navigation": "네비게이션",
    "Weather": "날씨",
    "Phone": "전화",
    "Video": "비디오",
    "Photo": "사진",
    "Music": "음악 추천",
    "Language": "한/영",
    "Settings": "설정"
  }
  
  const tileObjects = document.querySelectorAll('.tile-text');
  tileObjects.forEach((element) => {
    element.textContent = tiles[element.textContent];
  });
  
  // Toggle the language
  language = language === 'korean' ? 'english' : 'korean';
}


