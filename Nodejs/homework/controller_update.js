const csv2json = require('convert-csv-to-json');
var json = csv2json.fieldDelimiter(',').getJsonFromCsv('employee.csv');
const fs = require('fs');

const multilang = require('./multilang.js');
function getCurrentLang(acceptlang){    //尋找多國語言
    let acceptlang_split1 = acceptlang.split(';');
    for (let i = 0; i < acceptlang_split1.length; i++)
    {
        let acceptlang_split2 = acceptlang_split1[i].split(',');
        for (let j = 0; j < acceptlang_split2.length; j++)
            if (multilang.employ_text[acceptlang_split2[j]])
                return multilang.employ_text[acceptlang_split2[j]];
    }
    return multilang.cht;   //default
}

exports.view_search = (req, res) => {

};
exports.feature_search = (req, res) => {

};