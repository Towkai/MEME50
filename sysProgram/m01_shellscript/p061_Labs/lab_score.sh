read -p "輸入一個分數(0~100)：" score
if [ $score -ge 90 -a $score -le 100 ]; then
    echo "優等"
elif [ $score -ge 80 ]; then
    echo "甲等"
elif [ $score -ge 70 ]; then
    echo "乙等"
elif [ $score -ge 60 ]; then
    echo "丙等"
elif [ $score -ge 0 ]; then
    echo "不及格"
else
    echo "輸入錯誤"
fi