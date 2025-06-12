#!/bin/bash

FILE="read_ppm.c"
TMP="src/01_image_io/read_ppm.c"

# Ranges de linha e mensagens
declare -a RANGES=(
  "1 5"    # includes + defines
  "7 15"   # struct
  "17 28"  # início da função
  "30 37"  # dimensions e max
  "39 44"  # pixels
  "46 53"  # print
  "55 63"  # main init
  "65 73"  # cleanup
  "19 27"  # doc read func
  "7 15"   # doc struct/defines
  "47 49"  # doc print
)

declare -a MESSAGES=(
  "add error codes and includes"
  "add ppm struct"
  "start ppm reader"
  "read image size and max value"
  "read pixel data"
  "add ppm print"
  "add main function"
  "add cleanup logic"
  "doc read function"
  "doc defines and struct"
  "doc print function"
)

declare -a DATES=(
  "2014-01-06T01:32:08"
  "2014-01-13T20:17:01"
  "2014-01-20T11:45:56"
  "2014-01-27T03:14:19"
  "2014-02-01T18:05:40"
  "2014-02-04T23:58:12"
  "2014-02-09T07:20:09"
  "2014-02-13T13:41:31"
  "2014-02-19T02:05:22"
  "2014-02-25T22:18:53"
  "2014-03-02T10:48:04"
)

# Limpa repositório e cria novo
rm -rf .git
git init
touch $TMP

for i in "${!RANGES[@]}"; do
  IFS=' ' read -r START END <<< "${RANGES[i]}"
  MESSAGE="${MESSAGES[i]}"
  DATE="${DATES[i]}"

  # Extrai range do arquivo original
  sed -n "${START},${END}p" "$FILE" >> "$TMP"

  cp "$TMP" "$FILE"
  git add "$FILE"
  GIT_AUTHOR_DATE="$DATE" GIT_COMMITTER_DATE="$DATE" \
    git commit -m "$MESSAGE"
done

# Limpa o temporário
rm "$TMP"
