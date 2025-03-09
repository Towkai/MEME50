BASEDIR=$(dirname $0)/test1
TEMPDIR=${BASEDIR}/temp
files=($(ls $BASEDIR))
mkdir ${TEMPDIR}
for file in ${files[@]}; do
    echo $file
    mv "${BASEDIR}/${file}" "${TEMPDIR}"
    mv "${TEMPDIR}/${file}" "${BASEDIR}/$(echo ${file} | tr '[:upper:]' '[:lower:]')"
done
rmdir ${TEMPDIR}