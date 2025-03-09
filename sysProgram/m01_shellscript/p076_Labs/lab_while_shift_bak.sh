BASEDIR=$(dirname $0)
while [ $# -gt 0 ]; do
    cp "${BASEDIR}/${1}" "${BASEDIR}/${1}.bak"
    shift
done