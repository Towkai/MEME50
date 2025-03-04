exports.employ = {
    enum: {
        uuid: 0,
        empno: 1,
        ename: 2,
        hiredate: 3,
        salary: 4,
        deptno: 5,
        title: 6
    },
    type: {
        uuid: "uuid",
        empno: "text",
        ename: "text",
        hiredate: "date",
        salary: "number",
        deptno: "select",
        title: "text"
    },
    deptno: ["100", "200", "300", "RD1", "RD2", "RD3", "RD4", "RD5", "RD6", "RD7", "RD8"]
}
exports._uuid = function() {    //參考 https://www.cythilya.tw/2017/03/12/uuid/ 方法3
    var d = Date.now();
    if (typeof performance !== 'undefined' && typeof performance.now === 'function'){
        d += performance.now(); //use high-precision timer if available
    }
    return 'xxxx-4xxx-yxxx-xxxxxxxxxxxx'.replace(/[xy]/g, function (c) {
        var r = (d + Math.random() * 16) % 16 | 0;
        d = Math.floor(d / 16);
            return (c === 'x' ? r : (r & 0x3 | 0x8)).toString(16);
    });
}