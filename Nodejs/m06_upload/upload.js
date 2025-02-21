const port = 8181;
const express = require('express');
const app = express();
const multer = require('multer');
const fs = require('fs');
const { Console } = require('console');
const upload = multer({ dest: "temp" });
app.listen(port, () => console.log(`Server running at http://localhost:${port}`));

app.post('/one', upload.single('file'), (req, res) => {
    console.log(req.file);
    const destPath = `./public/img/${req.file.originalname}`;
    const readStream = fs.createReadStream(req.file.path);
    const writeStream = fs.createWriteStream(destPath);

    // 處理讀取錯誤
    readStream.on('error', err => {
        console.error('Read error:', err);
        res.status(500).send('Error reading the file');
    });

    // 處理寫入錯誤
    writeStream.on('error', err => {
        console.error('Write error:', err);
        res.status(500).send('Error writing the file');
    });

    // 當讀取完成時返回成功訊息
    readStream.on('end', () => {
        res.end('Upload success');
    });

    readStream.pipe(writeStream);
});

const maxCount = 5;
app.post('/multi', upload.array('file', { maxCount: maxCount }), (req, res) => {
    console.log(req.files);
    for (let i = 0; i < req.files.length; i++) {
        console.log(req.files[i].path);
        const destPath = `./public/img/${req.files[i].originalname}`;
        const readStream = fs.createReadStream(req.files[i].path);
        const writeStream = fs.createWriteStream(destPath);

        // 處理讀取錯誤
        readStream.on('error', err => {
            console.error('Read error:', err);
            res.status(500).send('Error reading the file');
        });

        // 處理寫入錯誤
        writeStream.on('error', err => {
            console.error('Write error:', err);
            res.status(500).send('Error writing the file');
        });

        // 當讀取完成時返回成功訊息
        writeStream.on('end', () => {
            console.log("write success");
        });
        readStream.on('end', () => {
            res.end('Upload success');
        });

        readStream.pipe(writeStream);
    }
});

// var fields = [
//     {name: 'file1'},
//     {name: 'file2'}
// ];
function fieldList(n)
{
    let fields = [];
    for (let i = 0; i < n; i++) {
        let field = {
            name: `file${i+1}`
        }
        fields.push(field);
    }
    return fields;
}
var fields;
app.post('/many', upload.fields(fields = fieldList(2)), (req, res) => {
    console.log(req.files);
    for (let i = 0; i < fields.length; i++) {
        const destPath = `./public/img/${req.files[fields[i].name][0].originalname}`;
        const readStream = fs.createReadStream(req.files[fields[i].name][0].path);
        const writeStream = fs.createWriteStream(destPath);

        // 處理讀取錯誤
        readStream.on('error', err => {
            console.error('Read error:', err);
            res.status(500).send('Error reading the file');
        });

        // 處理寫入錯誤
        writeStream.on('error', err => {
            console.error('Write error:', err);
            res.status(500).send('Error writing the file');
        });

        // 當讀取完成時返回成功訊息
        readStream.on('end', () => {
            res.end('Upload success');
        });

        readStream.pipe(writeStream);
    }
});
