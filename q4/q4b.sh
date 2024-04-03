read text
words=$(echo -n "$text" | wc -w)
characters=$(echo -n "$text" | wc -c)
spaces=$(echo -n "$text" | tr -cd '[:space:]' | wc -c)
special=$(echo -n "$text" | tr -cd '[:punct:]' | wc -c)

    echo "Number of characters: $characters"
    echo "Number of words: $words"
    echo "Number of white spaces: $spaces"
    echo "Number of special symbols: $special"
