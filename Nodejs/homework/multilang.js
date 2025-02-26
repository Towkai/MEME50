const employ_empty = {
    empno: '',
    ename: '',
    hiredate: '',
    salary: '',
    deptno: '',
    title: ''
}
const employ_en  = {
    insert_status: {
        failed: 'insert failed',
        success: 'insert success'
    },
    empno: "empno",
    ename: "ename",
    hiredate: "hiredate",
    salary: "salary",
    deptno: "deptno",
    title: "title"
}
const employ_cht = {
    empno: "員編：",
    ename: "姓名：",
    hiredate: "到職日：",
    salary: "薪資：",
    deptno: "部編：",
    title: "職稱："
}
const employ_chs = {
    empno: "员编：",
    ename: "姓名：",
    hiredate: "到职日：",
    salary: "薪资：",
    deptno: "部编：",
    title: "职称："
}
exports.employ = {
    empno: 0,
    ename: 1,
    hiredate: 2,
    salary: 3,
    deptno: 4,
    title: 5
}
exports.employ_text = {
    empty: {caption: '', content: employ_empty},
    "en": {caption: 'insert', insert_status: {failed: {incomplete: 'data incomplete', repeat: 'empno repeat'},success: 'success'}, content: employ_en},
    "zh-CN": {caption: '新增员工', insert_status: {failed: {incomplete: '资料不齐', repeat: '已有此员编'},success: '新增成功'}, content: employ_chs},
    "zh-TW": {caption: '新增員工', insert_status: {failed: {incomplete: '資料不齊', repeat: '已有此員編'},success: '新增成功'}, content: employ_cht}
}
exports.getCurrentLang = function(acceptlang) {    //尋找多國語言
    let acceptlang_split1 = acceptlang.split(';');
    for (let i = 0; i < acceptlang_split1.length; i++)
    {
        let acceptlang_split2 = acceptlang_split1[i].split(',');
        for (let j = 0; j < acceptlang_split2.length; j++)
            if (this.employ_text[acceptlang_split2[j]])
                return this.employ_text[acceptlang_split2[j]];
    }
    return cht;   //default
}