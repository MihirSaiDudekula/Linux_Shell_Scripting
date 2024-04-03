BEGIN {
    print "Removing Duplicated lines"
}

{
    line[$0]++
}

END {
    for (line in line) {
        if (line[line] == 1) {
            print line > "out13a.txt"
        }
    }
}

