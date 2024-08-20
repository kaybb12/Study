// 지도 관련 js 코드
window.onload = function() {
  let mapContainer = document.querySelector('#map');
  let mapOption = { 
        center: new kakao.maps.LatLng(37.50136, 127.0396), // 지도의 중심좌표
        level: 3, // 지도의 확대 레벨
        mapTypeId: kakao.maps.MapTypeId.ROADMAP // 지도종류
    };

let map = new kakao.maps.Map(mapContainer, mapOption); 

// 빌딩이미지(싸피건물)
 let imageSrc = "./img/building.png";
 let imageSize = new kakao.maps.Size(64,69);
 let imageOtion = {offset : new kakao.maps.Point(32, 60)}

 let initialMarkerImage = new kakao.maps.MarkerImage(
  imageSrc,
  imageSize,
  imageOtion
 );

 let initialMarkerPositon = new kakao.maps.LatLng(37.50136, 127.0396);


 let initialMarKer = new kakao.maps.Marker({
  image : initialMarkerImage,
  position : initialMarkerPositon
 });

 initialMarKer.setMap(map);


 let initailInfoWindow = new kakao.maps.InfoWindow({
  content: `<div style="color: gray; font-size:10px; padding:5px">역삼 멀티 캠퍼스에서 출발</div>`
 });
 

 initailInfoWindow.open(map, initialMarKer);

//장소검색개체 생성
let ps = new kakao.maps.services.Places();

// 마커 객체
let markers = [];

// 전역
let infowindow = new kakao.maps.InfoWindow();
let polyline = new kakao.maps.Polyline();

// 검색
const searchFunction = function(event) {
  // Enter 키가 아닌 경우 또는 검색어가 없는 경우에는 함수 실행을 종료
  if (event.type === 'keyup' && event.key !== 'Enter') return;
  infowindow.close(); 
  
  let keyword = document.querySelector('#search-input').value;
  if (!keyword.trim()) {
  alert('키워드를 입력해주세요!');
  return;
  }
  
  // 장소검색 객체를 통해 키워드로 장소검색
  ps.keywordSearch(keyword, placesSearchCB);
  infowindow.setMap(null);
  polyline.setMap(null);
};

// 검색버튼 클릭 이벤트 추가
document.getElementById('search-button').addEventListener('click', searchFunction);

// 검색버튼 키보드 이벤트 추가
document.getElementById('search-input').addEventListener('keyup', searchFunction);

// 장소검색 콜백
function placesSearchCB(data, status, pagination) {
  if (status === kakao.maps.services.Status.OK) {
  // 검색 결과 목록에 추가합니다
  displayPlaces(data);
  } else {
  alert('검색 결과가 없습니다.');
  }
}

// 마커 추가
function displayPlaces(places) {
  let listEl = document.querySelector('.search-results');
  listEl.innerHTML = '';

  //마커 제거
  removeMarkers();

  for (let i = 0; i < places.length; i++) {
    let itemEl = document.createElement('div');
    itemEl.className = 'item';
    itemEl.innerHTML = `
      <div class="info">
        <b>${places[i].place_name}</b>
        <br/><br/>
        <span>${places[i].road_address_name}</span>
        <span class="tel">${places[i].phone}</span>
      </div>
    `;
    itemEl.addEventListener('click', function() {
      infowindow.close();
      // 클릭된 장소의 좌표를 지도 중심으로 설정합니다
      let centerPosition = new kakao.maps.LatLng(places[i].y, places[i].x);
      map.setCenter(centerPosition);

      // startNavigation(places[i]);
      infowindow = new kakao.maps.InfoWindow({
        content : `<div style="padding:5px; color:gray;font-size:1.1vw;">${places[i].place_name}
        </div>` // 인포윈도우에 표시할 내용
        });
        infowindow.open(map, marker);
        getCarDirection(initialMarkerPositon, centerPosition);
      });
      listEl.appendChild(itemEl);

      // 마커를 지도에 추가합니다
      let marker = new kakao.maps.Marker({
        position: new kakao.maps.LatLng(places[i].y, places[i].x)
      });
      
      marker.setMap(map);
      markers.push(marker);
      
      kakao.maps.event.addListener(marker, 'click', function() {
        infowindow.close();
        // 클릭된 장소의 좌표를 지도 중심으로 설정합니다
        let centerPosition = new kakao.maps.LatLng(places[i].y, places[i].x);
        map.setCenter(centerPosition); 
        infowindow = new kakao.maps.InfoWindow({
          content : `<div style="padding:5px; color:gray;font-size:1.1vw;">${places[i].
            place_name}</div>` // 인포윈도우에 표시할 내용
            });
            infowindow.open(map, marker);
            getCarDirection(initialMarkerPosition, centerPosition);
          });
        }
      }
      
// 지도 위에 표시되고 있는 마커를 모두 제거하는 함수입니다
function removeMarkers() {
  for (let i = 0; i < markers.length; i++) {
    markers[i].setMap(null);
  } 
  markers = [];
}

async function getCarDirection(startPosition, destinationPosition) {
  const REST_API_KEY = "3d309dda3dd259a6b1e56b7a708f7ac6";
  // 호출방식의 URL을 입력합니다.
  const url = "https://apis-navi.kakaomobility.com/v1/directions";
  // 출발지(origin), 목적지(destination)의 좌표를 문자열로 변환합니다.
  const origin = `${startPosition.La},${startPosition.Ma}`;
  const destination = `${destinationPosition.La},${destinationPosition.Ma}`;
  // 요청 헤더를 추가합니다.
  const headers = {
  Authorization: `KakaoAK ${REST_API_KEY}`,
  "Content-Type": "application/json",
  };
  // 공식문서 표3의 요청 파라미터에 필수값을 적어줍니다.
  const queryParams = new URLSearchParams({
  origin: origin,
  destination: destination,
  });
  const requestUrl = `${url}?${queryParams}`; // 파라미터까지 포함된 전체 URL
  try {
  const response = await axios.get(requestUrl, { headers: headers });
  if (response.status !== 200) {
  throw new Error(`HTTP error! Status: ${response.status}`);
  }
  const data = response.data;
  console.log("data = ", data);
  const linePath = [];
  data.routes[0].sections[0].roads.forEach((router) => {
    router.vertexes.forEach((vertex, index) => {
      // 인덱스가 짝수일 때만 linePath에 추가하여야 정상적으로 그려짐
      if (index % 2 === 0) {
       linePath.push(
       new kakao.maps.LatLng(
       router.vertexes[index + 1],
       router.vertexes[index]
       )
       );
       }
       });
       });
       polyline.setMap(null);
       polyline = new kakao.maps.Polyline({
       path: linePath,
       strokeWeight: 5,
       strokeColor: "#000000",
       strokeOpacity: 0.7,
       strokeStyle: "solid",
       });
       polyline.setMap(map);
       // 거리가 지도 범위보다 크면 자동으로 지도 bound 설정
       let initialInfowindowBounds = new kakao.maps.LatLng(37.50936, 127.0396);
       let bounds = new kakao.maps.LatLngBounds(
       initialInfowindowBounds,
       destinationPosition
       );
       bounds.extend(initialMarkerPositon);
       map.setBounds(bounds);
       } catch (error) {
       console.error("Error:", error);
       }
      }
}


 