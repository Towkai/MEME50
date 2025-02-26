const fs = require('fs');
const readline = require('readline');
const ejs_file = "index.ejs";

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
const { text } = require('stream/consumers');
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

exports.get = (req, res) => {
    let text = getCurrentLang(req.headers['accept-language']);
    res.render(ejs_file, {  //固定用法：建立名為"views"的資料夾，將"insert.ejs"放在裡面
        status:'',
        caption: text.caption,
        text: text.content
    });
};