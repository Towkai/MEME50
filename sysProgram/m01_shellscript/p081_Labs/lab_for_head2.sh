BASEDIR=$(dirname $0)/test3
file_heads=${BASEDIR}/../file_heads
files=($(ls $BASEDIR))
if [ -e "$file_heads" ]; then
    rm $file_heads
fi
for file in ${files[@]}; do
    if [[ ${file} =~ \.html$ ]]; then
        count=0
        for line in $(cat "${BASEDIR}/${file}"); do
            if [ ${count} -lt 2 ]; then
                echo "$line" >> "$file_heads"
                ((count=count+1))
            else
                break
            fi
        done
    fi
done