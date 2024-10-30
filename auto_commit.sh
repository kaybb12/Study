#!/bin/bash

# 현재 디렉토리의 모든 파일 재귀적으로 탐색
FILES=$(find . -type f 2>/dev/null)

# 각 파일에 대해 작업 수행
for FILE in $FILES; do
  # .git 디렉토리는 무시
  if [[ $FILE == *"/.git"* ]]; then
    continue
  fi

  # 파일이 서브모듈에 속한 경우 무시
  if git ls-files --error-unmatch "$FILE" &>/dev/null; then
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
  else
    echo "Skipping submodule file: $FILE"
  fi
done

