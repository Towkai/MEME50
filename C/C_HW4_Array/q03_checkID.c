#include<stdio.h>
#include<ctype.h>
#include"../myheaders/myarr.h"
#include"../myheaders/myfunc.h"

/*
寫一函數 boolean isID (String id)用來判斷 id 是否為正確身份証字號
*/
int isID(char id[]);
int check_length10(char id[]); //檢查是否十位
int check_index0_isupper(char id[]); //檢查是否英文大寫字母開頭
int check_index1_is1or2(char id[]); //檢查第二位是否為1或2
int check_index2toF_isdigit(char id[]); //檢查第三位到最後是否為數字
int check_auth(char id[]);   //檢查驗證碼
int convert_start_char_to_int(char start_char) //轉換英文為數字(按照身分證規則，A to Z對應10 to 33)
{
    switch (start_char)
    {       
        case 'A': return 10;
        case 'B': return 11;
        case 'C': return 12;
        case 'D': return 13;
        case 'E': return 14;
        case 'F': return 15;
        case 'G': return 16;
        case 'H': return 17;
        case 'I': return 34;
        case 'J': return 18;
        case 'K': return 19;
        case 'L': return 20;
        case 'M': return 21;
        case 'N': return 22;
        case 'O': return 35;
        case 'P': return 23;
        case 'Q': return 24;
        case 'R': return 25;
        case 'S': return 26;
        case 'T': return 27;
        case 'U': return 28;
        case 'V': return 29;
        case 'W': return 32;
        case 'X': return 30;
        case 'Y': return 31;
        case 'Z': return 33;
    }
}
char* convert_letter_to_digit(char id[])    ////從英文轉換的數字按照定義產生新的字串
{
    int convert_letter = convert_start_char_to_int(id[0]);
    int new_start = (get_number_of_digit(convert_letter, 0) * 9 + get_number_of_digit(convert_letter, 1)) % 10;
    id[0] = new_start + '0';
    return id;
}
int sum_char(char id[])
{
    int rule_list[] = { 1, 8, 7, 6, 5, 4, 3, 2, 1};
    char* new_id = convert_letter_to_digit(id);
    int sum = 0;
    for (int i = 0; i < LENGTH(rule_list); i++)
        sum += (new_id[i] - '0') * rule_list[i];
    return sum;
}

void main()
{
    char input[11] = {};
    scanf("%s", &input);
    printf("檢查是否十位：");
    int is_length10 = check_length10(input);
    printf("%s\n", BOOLEAN(is_length10));

    printf("檢查首位英文字母：");
    int is_index0_isupper = check_index0_isupper(input);
    printf("%s\n", BOOLEAN(is_index0_isupper));

    printf("檢查第二位是否為1或2：");
    int is_index1_is1or2 = check_index1_is1or2(input);
    printf("%s\n", BOOLEAN(is_index1_is1or2));
    
    printf("檢查第三位到最後是否為數字：");
    int is_index2toF_isdigit = check_index2toF_isdigit(input);
    printf("%s\n", BOOLEAN(is_index2toF_isdigit));

    printf("驗證碼檢驗：");
    int is_auth = check_auth(input);
    printf("%s\n", BOOLEAN(is_auth));

    printf("是否為正確的身分證字號：%s", BOOLEAN(is_length10 & is_index0_isupper & is_index1_is1or2 & is_index2toF_isdigit & is_auth));
    
}

int isID(char id[])
{
    // return check_length10(id) & 
}

int check_length10(char id[])
{
    int index = 0;
    while (id[index] != '\0')
        index++;
    if (index == 10)
        return 1;
    else
        return 0;
}
int check_index0_isupper(char id[])
{
    return isupper(id[0]);
}
// int check_index0_isupper(char id[])
// {
//     if ((int)id[0] >= 65 && (int)id[0] <= 90)
//     {
//         int i = 1;
//         while (id[i] != '\0')
//         {
//             if ((int)id[i] < 48 && (int)id[i] > 57)
//                 return 0;
//             i++;
//         }
//         return 1;
//     }
//     return 0;
// }
int check_index1_is1or2(char id[])
{
    return (id[1] == '1' || id[1] == '2');
}
int check_index2toF_isdigit(char id[])
{
    for (int i = 2; id[i] != '\0'; i++)
    {
        if (!isdigit(id[i]))
            return FALSE;
    }
    return TRUE;
}
int check_auth(char id[])
{
    int sum = sum_char(id);
    return 10 - (sum % 10) == id[9] - '0';
}