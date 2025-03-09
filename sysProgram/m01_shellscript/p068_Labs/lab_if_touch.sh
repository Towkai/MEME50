BASEDIR=$(dirname $0)
if [[ -e "${BASEDIR}/logical" ]]; then
    if [[ -f "${BASEDIR}/logical" ]]; then
        echo "${BASEDIR}/logical 為檔案，刪除並建立同名資料夾"
        rm "${BASEDIR}/logical" | mkdir "${BASEDIR}/logical"
    else
        echo "${BASEDIR}/logical 為目錄，移除"
        rmdir "${BASEDIR}/logical"
fi
else
    echo "${BASEDIR}/logical 不在，以touch建立"
    touch "${BASEDIR}/logical"
    exit 0
fi