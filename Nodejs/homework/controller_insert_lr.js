const fs = require('fs');
const readline = require('readline');
const ejs_file = "insert.ejs";
const csv_file = "employee.csv";

var empno_repeat = null;

function lineReader(file)
{
    let inputStream = fs.createReadStream(file);
    return readline.createInterface({ input: inputStream });
}
function check_repeat_empno(lineReader, empno) {
    lineReader.on('line', line => {
        if (line.split(',')[multilang.employ.empno] == empno)
            return empno_repeat = true;
    });
}

const multilang = require('./multilang.js');

exports.view_insert = (req, res) => {
    let employ = {};
    employ.hiredate = new Date().toLocaleDateString('en-CA', {timeZone: 'Asia/Taipei', hour12: false });
    let text = multilang.getCurrentLang(req.headers['accept-language']);
    res.render(ejs_file, {  //固定用法：建立名為"views"的資料夾，將"insert.ejs"放在裡面
        status:'',
        caption: text.caption,
        text: text.content,
        employ_value: employ
    });
};
exports.feature_insert = (req, res) => {
    let body = req.body;
    if (!body.empno || !body.ename || !body.hiredate || !body.salary || !body.deptno || !body.title) {
        res.send("資料不齊");
        return;
    }

    let lr = lineReader(csv_file);
    check_repeat_empno(lr, body.empno);

    lineReader.on('close', () => {
        if (empno_repeat == true)
        {
            res.send("已有此編號");
        }
        else
        {
            let data = [];    
            for (let key in body) {
                data.push(body[key]);
            }
            fs.appendFile(csv_file, `\n${data.join(',')}`, err => {
                if (err) throw err;
            });
            res.send('寫入完成');
        }
    });
};