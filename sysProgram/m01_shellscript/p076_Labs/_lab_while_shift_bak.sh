function mycmd() {
    echo $0
    echo $1
    echo $2
    echo $3
    echo $4
    for ((i = 1; i < $#; i++))
    do
        echo "$(`$i`)"
        echo $i
    done
}
read -p "輸入mycmd f1 f2 f3 f4 ... fn: " -e input
echo ${input}
mycmd ${input}