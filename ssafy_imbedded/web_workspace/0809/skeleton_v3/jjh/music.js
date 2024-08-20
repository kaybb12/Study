document.getElementById('recommend-btn').addEventListener('click', () => {
    // 랜덤 키워드 배열 생성
    const randomKeywords = [
        "joy music",
        "positive music",
        "sadness music",
        "anger music",
        "fear music",
        "disgust music",
        "anxiety music",
        "envy music",
        "embarrassment music",
        "ennui music"
    ];

    // 랜덤으로 키워드 선택
    const randomIndex = Math.floor(Math.random() * randomKeywords.length);
    const randomKeyword = randomKeywords[randomIndex];
    const keyword = `${randomKeyword}`;

    // 결과 표시
    document.getElementById('result').textContent = `추천 음악 키워드: ${keyword}`;

    // YouTube 검색 및 첫 번째 영상 재생
    searchAndPlayYouTube(keyword);
});

function searchAndPlayYouTube(keyword) {
    const apiKey = 'AIzaSyAeYoKAA7a7HBKiA_R7qJlCHMdIUzR8eOw'; // YouTube Data API 키
    const searchUrl = `https://www.googleapis.com/youtube/v3/search?part=snippet&q=${encodeURIComponent(keyword)}&type=video&key=${apiKey}&maxResults=1`;

    fetch(searchUrl)
        .then(response => response.json())
        .then(data => {
            if (data.items && data.items.length > 0) {
                const videoId = data.items[0].id.videoId;
                const embedUrl = `https://www.youtube.com/embed/${videoId}?autoplay=1`;
                document.getElementById('youtubePlayer').src = embedUrl;
            } else {
                console.error('No videos found');
            }
        })
        .catch(error => console.error('Error fetching YouTube data:', error));
}