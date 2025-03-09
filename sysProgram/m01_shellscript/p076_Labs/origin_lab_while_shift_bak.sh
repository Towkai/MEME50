function mycmd() {
    if [ $1 == "mycmd" ]; then
        count=0
        for item in "${@}"; do
            if [ ${count} -gt 0 ] && [[ ${item} =~ ^[Ff][0-9]+$ ]]; then
                farr+=("${item}.bak")
            fi
            count=$[$count+1]
        done
        echo "${farr[@]}"
    fi
}
read -p "輸入mycmd f1 f2 f3 f4 ... fn: " -e input
mycmd ${input}