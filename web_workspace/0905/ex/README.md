
# 주문 시스템 프로젝트

이 프로젝트는 Firebase를 이용하여 주문과 메뉴를 관리하는 웹 애플리케이션입니다. Vue.js를 기반으로 구축되었으며, 사용자와 관리자를 위한 다양한 기능을 제공합니다.

## 주요 기능

### 사용자 기능
- **메뉴 조회**: 사용자는 등록된 모든 메뉴를 조회할 수 있습니다.
- **주문 생성 및 조회**: 사용자는 메뉴를 선택하여 주문을 생성하고, 자신의 주문 내역을 조회할 수 있습니다.
- **주문 상세 및 결제**: 개별 주문의 상세 정보를 확인하고, 결제를 진행할 수 있습니다.

### 관리자 기능
- **메뉴 관리**: 관리자는 메뉴를 추가, 수정, 삭제할 수 있습니다.
- **메뉴 상세 조회**: 각 메뉴의 상세 정보를 확인할 수 있습니다.
- **주문 관리**: 모든 주문 내역을 관리하고, 상세 정보를 조회할 수 있습니다.

## 설치 및 실행 방법

### 실행

1. 해당링크로 접속 하시면 됩니다.
http://chiwon.p-e.kr/

## 폴더 구조

- `/src/utils/firebase_api.js`: Firebase 초기화 및 Firestore와 Storage와 상호작용하는 함수들이 정의되어 있습니다.
- `/src/router/index.js`: Vue Router 설정 파일로, 각 페이지 컴포넌트에 대한 경로를 관리합니다.
- `/src/views/admin-menu`: 관리자용 메뉴 관리 페이지들이 위치합니다. 
  - `MainView.vue`: 관리자 대시보드
  - `ListView.vue`: 메뉴 목록 페이지
  - `DetailView.vue`: 메뉴 상세 보기 페이지
  - `RegisterView.vue`: 메뉴 등록 및 수정 페이지
- `/src/views/order`: 사용자 주문 관련 페이지들이 위치합니다.
  - `MainView.vue`: 메인 페이지
  - `ListView.vue`: 주문 목록 페이지
  - `DetailView.vue`: 주문 상세 페이지
  - `RegisterView.vue`: 주문 등록 페이지
  - `OrderDetail.vue`: 주문 세부 사항 확인 페이지
  - `EndView.vue`: 결제 페이지

## 사용된 기술

- **Vue.js**: 프론트엔드 프레임워크
- **Firebase**: 백엔드 서비스로 Firestore와 Storage 사용
- **Vue Router**: 애플리케이션 내의 라우팅 관리

## 환경 설정

- Node.js 버전: 14 이상
- Firebase 설정 정보는 `/src/utils/firebase_api.js`에 포함되어 있습니다.
