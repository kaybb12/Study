# order-system API

이 문서에서는 `order-system` API의 사용 방법을 설명합니다. 이 API는 Firebase Firestore와 Firebase Storage를 사용하여 메뉴, 주문 데이터를 관리합니다.

## API Methods

### `menus`

#### `findAll()`

모든 메뉴를 조회합니다. 각 메뉴의 이미지 URL도 함께 반환됩니다.

#### `findOne(id)`

특정 ID를 가진 메뉴를 조회합니다. 해당 메뉴의 이미지 URL도 함께 반환됩니다.

#### `create(name, description, file)`

새로운 메뉴를 생성하고, 이미지 파일을 Firebase Storage에 업로드합니다.

#### `update(id, newName, newDescription)`

기존 메뉴의 이름과 설명을 업데이트합니다.

#### `updateImage(originalMenu, newFile)`

기존 메뉴의 이미지를 업데이트합니다. 기존 이미지는 Firebase Storage에서 삭제됩니다.

#### `delete(originalMenu)`

기존 메뉴를 삭제합니다. Firebase Storage에 저장된 이미지도 함께 삭제됩니다.

### `orders`

#### `findAll()`

모든 주문을 조회합니다. 각 주문의 주문ID도 함께 반환됩니다.

#### `findOne(id)`

특정 ID를 가진 주문을 조회합니다. 해당 주문의 주문ID도 함께 반환됩니다.

#### `create(quantity, request_detail, mdID)`

새로운 주문을 생성합니다.

#### `update(id, newName, newDescription)`

기존 주문의 수량과 옵션을 업데이트합니다.

#### `delete(originalMenu)`

기존 주문을 삭제합니다.

## Usage

메뉴 API를 사용하려면 app.js 파일에서 api 객체를 가져와 원하는 메서드를 호출하면 됩니다:

import { api } from './app.js';

// 모든 메뉴 찾기
const menus = await api.menus.findAll();

// 단일 메뉴 찾기
const menu = await api.menus.findOne('찾는 메뉴 아이디');

// 새 메뉴 생성하기
const newMenu = await api.menus.create('새로운 메뉴 이름', '메뉴 설명', menuImageFile);

// 기존 메뉴 업데이트하기
await api.menus.update('업데이트할 메뉴 아이디', '업데이트할 이름','업데이트 할 이름');

// 기존 메뉴 이미지 업데이트하기
await api.menus.updateImage(단일 메뉴 찾기로 찾은 메뉴, 새로운 이미지 파일);

// 메뉴 삭제하기
await api.menus.delete(단일 메뉴 찾기로 찾은 메뉴);

주문 API를 사용하려면 app.js 파일에서 api 객체를 가져와 원하는 메서드를 호출하면 됩니다:

import { api } from './app.js';

// 모든 주문 찾기
const orders = await api.orders.findAll();

// 단일 주문 찾기
const menu = await api.orders.findOne('찾는 주문 아이디');

// 새 주문 생성하기
const newMenu = await api.orders.create('주문 수량', '주문 옵션', '주문 메뉴');

// 기존 주문 업데이트하기
await api.orders.update('업데이트할 주문 아이디', '업데이트할 수량','업데이트 할 옵션','업데이트할 메뉴')

// 주문 삭제하기
await api.orders.delete(단일 주문 찾기로 찾은 주문);