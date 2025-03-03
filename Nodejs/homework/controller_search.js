const fs = require('fs');
const csv_file = "employee.csv";
const ejs_file = "insert.ejs";
const csv2json = require('convert-csv-to-json');
var json = csv2json.fieldDelimiter(',').getJsonFromCsv(csv_file);
const employ = require('./employ.js').employ;
const multilang = require('./multilang.js');

function search_csv(body) {
    console.log(body);

    let keys = Object.keys(body);
    let result = [];
    for (let i = 0; i < json.length; i++)
        for (let j = 0; j < keys.length; j++)
        {
            if (body[keys[j]] == '')
                continue;
            if (json[i][keys[j]] == (body[keys[j]]))
                if (json[i][keys[j]].toLowerCase().includes(body[keys[j]]))
                    result.push(json[i]);
        }
    console.log(result);
    return result;
}

exports.view_search = (req, res) => {
    let text = multilang.getCurrentLang(req.headers['accept-language']);
    let selected = req.query;
    res.render('search.ejs', {  //固定用法：建立名為"views"的資料夾，將"insert.ejs"放在裡面
        data_type: employ.type,
        input_value: req.query,
        caption: text.caption.search,
        options: text.content,
        selected: selected,
        result: {}
    });
};
exports.feature_search = (req, res) => {
    let text = multilang.getCurrentLang(req.headers['accept-language']);

    res.render('search.ejs', {  //固定用法：建立名為"views"的資料夾，將"insert.ejs"放在裡面
        data_type: employ.type,
        input_value: req.body,
        caption: text.caption.search,
        options: text.content,
        // selected: '',
        result: search_csv(req.body)
        // result: {}
    });
};

function get_deptnos() {
    const deptnos = new Set();
    for (let i = 0; i < json.length; i++)
        deptnos.add(json[i]["deptno"]);
    return deptnos;
}