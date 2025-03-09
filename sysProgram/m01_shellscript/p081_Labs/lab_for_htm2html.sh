BASEDIR=$(dirname $0)/test2
files=($(ls $BASEDIR))
for file in ${files[@]}; do
    if [[ ${file} =~ \.htm$ ]]; then
        mv "${BASEDIR}/${file}" "${BASEDIR}/${file%.*}.html"
    fi
done