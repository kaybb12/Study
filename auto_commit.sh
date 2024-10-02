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

# 특정 파일 패턴 (.c, .cpp, .txt 파일만 커밋하고 싶을 때)
FILE_PATTERN="*.c *.cpp *.txt"

# 현재 디렉토리에서 작업할 폴더 내의 특정 파일 재귀적 탐색
FILES=$(find "$TARGET_DIR" -type f \( -name "*.c" -o -name "*.cpp" -o -name "*.txt" \) 2>/dev/null)

# 각 파일에 대해 작업 수행
for FILE in $FILES; do
  # .git 디렉토리 또는 서브모듈 파일 무시
  if [[ $FILE == *"/.git/"* ]] || [[ $FILE == *"/.git"* ]] || [[ $FILE == *"algo/JJH"* ]]; then
    echo "Skipping submodule or .git directory: $FILE"
    continue
  fi

  # 파일이 존재하는지 확인
  if [[ ! -f "$FILE" ]]; then
    echo "Warning: File $FILE does not exist. Skipping..."
    continue
  fi

  # 파일의 마지막 수정 시간 가져오기
  LAST_MODIFIED_DATE=$(stat -c "%y" "$FILE" 2>/dev/null)

  # 파일을 스테이징하고 커밋
  git add "$FILE"
  GIT_AUTHOR_DATE="$LAST_MODIFIED_DATE" GIT_COMMITTER_DATE="$LAST_MODIFIED_DATE" git commit -m "Auto commit for $FILE with last modified date"
done

# 최종 커밋 이후에 푸시
git push origin master

