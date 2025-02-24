const port = 8181;
const express = require('express');
const app = express();
app.listen(port, () => console.log(`Server running at http://localhost:${port}`));

app.set('view engine', 'ejs');
app.get('/', (req, res) => {
    res.render('output.ejs', {  //固定用法：建立名為"views"的資料夾，將"output.ejs"放在裡面
        title: 'ejs test',
        category: '<p><b>user: </b></p>',
        users: ['Tom', 'Jimmy', 'Tina'],
        emp: {
            empno: 1001,
            ename: '潘',
            hiredate: '2010-11-09',
            salary: 56e3,
            deptno: 100,
            title: 'senior engineer`'
        }
    });
});