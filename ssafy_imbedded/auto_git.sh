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

# 각 파일을 개별적으로 스테이징하고 커밋 수행
IFS=$'\n' # IFS를 설정하여 find 명령의 결과를 올바르게 분리
FILES=$(find "$TARGET_DIR" -type f ! -path "*/.git/*" ! -path "*/node_modules/*" ! -name '*.exe' -not -path "*/*/.git/*" -not -path "*/.gitmodules/*")

for FILE in $FILES; do
  # 파일의 마지막 수정 시간 가져오기 (Unix 타임스탬프 형식)
  if [[ -f "$FILE" ]]; then
    LAST_MODIFIED_TIMESTAMP=$(stat -c "%Y" "$FILE")
    if [[ -n "$LAST_MODIFIED_TIMESTAMP" ]]; then
      LAST_MODIFIED_DATE_FORMATTED=$(date -d @$LAST_MODIFIED_TIMESTAMP "+%Y-%m-%dT%H:%M:%S%z")

      # 파일을 스테이징하고 커밋, gitignore된 파일 제외
      if git check-ignore -q "$FILE"; then
        continue
      fi
      git add "$FILE"
      GIT_AUTHOR_DATE="$LAST_MODIFIED_DATE_FORMATTED" GIT_COMMITTER_DATE="$LAST_MODIFIED_DATE_FORMATTED" git commit --date="$LAST_MODIFIED_DATE_FORMATTED" -m "Auto commit for file: $FILE with last modified date"
    fi
  fi
done

# 줄바꿈 경고 방지를 위한 Git 설정
git config core.autocrlf true
