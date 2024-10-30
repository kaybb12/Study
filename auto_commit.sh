#!/bin/bash

# 작업할 폴더 경로 설정
TARGET_DIR="$1"

# TARGET_DIR이 제공되지 않은 경우, 스크립트 사용법 출력 후 종료
if [[ -z "$TARGET_DIR" ]]; then
  echo "Usage: $0 <target_directory>"
  exit 1
fi

# TARGET_DIR 존재 여부 확인
if [[ ! -d "$TARGET_DIR" ]]; then
  echo "Error: Directory $TARGET_DIR does not exist."
  exit 1
fi

# .git 디렉토리와 .exe 파일을 제외하고 모든 파일을 스테이징
find "$TARGET_DIR" -type f ! -path "*/.git/*" ! -path "*/node_modules/*" ! -name "*.exe" -exec git add {} +

# 모든 변경 사항을 스테이징
git add -A

# 변경 사항이 있는 경우에만 커밋
if ! git diff --cached --quiet; then
  git commit -m "Auto commit for all changes"
fi

# 커밋 이후에 푸시
git push origin master

