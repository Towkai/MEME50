const fs = require('fs');
const csv_file = "employee.csv";
const ejs_file = "insert.ejs";
const csv2json = require('convert-csv-to-json');
var json = csv2json.fieldDelimiter(',').getJsonFromCsv(csv_file);


const multilang = require('./multilang.js');

function search_csv(body) {
    let keys = Object.keys(body);
    let result = [];
    for (let i = 0; i < json.length; i++)
        for (let j = 0; j < keys.length; j++)
        {
            let term = true;
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
        input_type: multilang.employ.type,
        caption: text.caption.search,
        options: text.content,
        selected: selected,
        result: {}
    });
};
exports.feature_search = (req, res) => {
    let text = multilang.getCurrentLang(req.headers['accept-language']);

    res.render('search.ejs', {  //固定用法：建立名為"views"的資料夾，將"insert.ejs"放在裡面
        input_type: multilang.employ.type,
        caption: text.caption.search,
        options: text.content,
        selected: '',
        result: search_csv(req.body)
    });
};