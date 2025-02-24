const csv2json = require('convert-csv-to-json');
var json = csv2json.fieldDelimiter(',').getJsonFromCsv('employee.csv');

exports.queryall = (req, res) => {
    res.render('queryall', {emps: json});
};

exports.queryone = (req, res) => {
    let empno = req.params["empno"];
    for (let i = 0; i < json.length; i++) {
        if (json[i].empno == empno) {
            emp = json[i];
            break;
        }
    }
    res.render('queryone', {emp: emp });
}