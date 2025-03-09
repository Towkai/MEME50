read -p "Your first name and last name:" fname lname
echo ${fname} ${lname:-"先生"}, Lets be friend! # ${變數:-預設值}