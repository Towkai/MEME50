const fs = require('fs');
const csv_file = "employee.csv";
const ejs_file = "insert.ejs";
const csv2json = require('convert-csv-to-json');
var json = csv2json.fieldDelimiter(',').getJsonFromCsv(csv_file);
const employ = require('./employ.js').employ;
const _uuid = require('./employ.js')._uuid;
const multilang = require('./multilang.js');


exports.view_insert = (req, res) => {
    let text = multilang.getCurrentLang(req.headers['accept-language']);
    res.render(ejs_file, {  //固定用法：建立名為"views"的資料夾，將"insert.ejs"放在裡面
        status:'',
        data_type: employ.type,
        caption: text.caption.insert,
        text: text.content,
        employ_value: {hiredate: new Date().toLocaleDateString('en-CA', {timeZone: 'Asia/Taipei', hour12: false })}
    });
};
exports.feature_insert = (req, res) => {
    let body = req.body;
    let text = multilang.getCurrentLang(req.headers['accept-language']);
    
    if (!body.empno || !body.ename || !body.hiredate || !body.salary || !body.deptno || !body.title) {
        res.send(text.status.insert.failed.incomplete);
        return;
    }
    body["uuid"] = _uuid();

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