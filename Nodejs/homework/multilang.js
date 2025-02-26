const caption = {
    en: { insert: "insert", search: "search"},
    cht: { insert: "新增員工", search: "員工搜尋"},
    chs: { insert: "新增员工", search: "员工搜索"}
}
const content = {
    empty:{ empno: '',ename: '',hiredate: '',salary: '',deptno: '',title: ''},
    en: { empno: "empno", ename: "ename", hiredate: "hiredate", salary: "salary", deptno: "deptno", title: "title"},
    cht: { empno: "員編", ename: "姓名", hiredate: "到職日", salary: "薪資", deptno: "部編", title: "職稱"},
    chs: { empno: "员编", ename: "姓名", hiredate: "到职日", salary: "薪资", deptno: "部编", title: "职称"},
}
const status = {
    insert: {
        en: {failed: {incomplete: 'data incomplete', repeat: 'empno repeat'},success: 'success'},
        cht: {failed: {incomplete: '資料不齊', repeat: '已有此員編'},success: '新增成功'},
        chs: {failed: {incomplete: '资料不齐', repeat: '已有此员编'},success: '新增成功'}
    }
}
exports.employ = {
    enum: {
        empno: 0,
        ename: 1,
        hiredate: 2,
        salary: 3,
        deptno: 4,
        title: 5
    },
    type: {
        empno: "text",
        ename: "text",
        hiredate: "date",
        salary: "number",
        deptno: "text",
        title: "text"
    }
}
exports.employ_text = {
    empty: {caption: '', content: content.empty},
    "en": {caption: caption.en, status: {insert: status.insert.en}, content: content.en},
    "zh-TW": {caption: caption.cht, status: {insert: status.insert.cht}, content: content.cht},
    "zh-CN": {caption: caption.chs, status: {insert: status.insert.chs}, content: content.chs},
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