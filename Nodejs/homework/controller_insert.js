const csv2json = require('convert-csv-to-json');
var json = csv2json.fieldDelimiter(',').getJsonFromCsv('employee.csv');
const fs = require('fs');
const csv_file = "employee.csv";

const multilang = require('./multilang.js');


exports.view_insert = (req, res) => {
    let employ = {};
    employ.hiredate = new Date().toLocaleDateString('en-CA', {timeZone: 'Asia/Taipei', hour12: false });
    let text = multilang.getCurrentLang(req.headers['accept-language']);
    res.render('insert.ejs', {  //固定用法：建立名為"views"的資料夾，將"insert.ejs"放在裡面
        status:'',
        caption: text.caption.insert,
        text: text.content,
        employ_value: employ
    });
};
exports.feature_insert = (req, res) => {
    let body = req.body;
    let text = multilang.getCurrentLang(req.headers['accept-language']);
    
    if (!body.empno || !body.ename || !body.hiredate || !body.salary || !body.deptno || !body.title) {
        res.send(text.status.insert.failed.incomplete);
        return;
    }

    for (let i = 0; i < json.length; i++) {
        if (json[i].empno == body.empno) {
            res.send(text.status.insert.failed.repeat);
            return;
        }
    }
    
    let data = [];    
    for (let key in body) {
        data.push(body[key]);
    }

    fs.appendFile(csv_file, `\n${data.join(',')}`, err => {
        if (err) throw err;
    });
    
    res.send(text.status.insert.success);
};