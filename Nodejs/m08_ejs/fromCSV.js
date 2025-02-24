const port = 8181;
const express = require('express');
const app = express();
const fs = require('fs');
app.listen(port, () => console.log(`Server running at http://localhost:${port}`));
const csv2json = require('convert-csv-to-json');

app.set('view engine', 'ejs');
var json

app.use((req, res, next) => {
    json = csv2json.fieldDelimiter(',').getJsonFromCsv('employee.csv');
    next();
})

app.get('/employee/getall', (req, res) => {
    res.render('query.ejs', {
        title: 'empoly form',
        emps: json
    });
});

app.get('/employee/search/:empno', (req, res) => {
    let empno = req.params.empno;
    for (let i = 0; i < json.length; i++) {
        if (json[i].empno == empno) {
            emp = [json[i]];
            break;
        }
    }
    res.render('query', {
        title: 'empoly form',
        emps: emp 
    });
});

var empoly = {
    empno: '',
    ename: '',
    hiredate: '',
    salary: '',
    deptno: '',
    title: ''
}
app.get('/employee/insert', (req, res) => {
    empoly = req.query;
    if (empoly.ename == '' || empoly.ename == '' || empoly.hiredate == '' || empoly.salary == '' || empoly.deptno == '' || empoly.title == '') {
        res.send("資料不齊");
        return;
    }

    for (let i = 0; i < json.length; i++) {
        if (json[i].empno == empoly.empno) {
            res.send("已有此編號");
            return;
        }
    }
    let data = [];
    data.push(empoly.empno);
    data.push(empoly.ename);
    data.push(empoly.hiredate);
    data.push(empoly.salary);
    data.push(empoly.deptno);
    data.push(empoly.title);
    fs.appendFile('employee.csv', `\n${data.join()}`, err => {
        if (err) throw err;
    });
    res.send('寫入完成');

});