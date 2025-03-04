const csv_file = "employee.csv";
const ejs_file = "index.ejs";
const csv2json = require('convert-csv-to-json');
var json = csv2json.fieldDelimiter(',').getJsonFromCsv(csv_file);
const employ = require('./employ.js').employ;
const multilang = require('./multilang.js');

exports.get = (req, res) => {
    let text = multilang.getCurrentLang(req.headers['accept-language']);
    res.render(ejs_file, {  //固定用法：建立名為"views"的資料夾，將"insert.ejs"放在裡面
        status:'',
        data_type: employ.type,
        content: text.content,
        data: json,
    });
};