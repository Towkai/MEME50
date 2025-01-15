window.addEventListener("load", (event) => {
    generate_table();
  });

function generate_table()
{
    let table = document.createElement('table');
    // table.setAttribute("border", "1");
    table.setAttribute("bgcolor", "Aqua");
    table.setAttribute("style", "color:red;border-style:ridge;border: 5px solid DodgerBlue;border-collapse: collapse")
    let title = document.createElement('caption');
    let tbody = document.createElement('tbody');
    title.textContent = "九九乘法表";
    table.appendChild(title);
    table.appendChild(tbody);
    
    for (let i = 1; i <= 9; i++)
    {
        let th = document.createElement('th');
        th.setAttribute("style", "border: 5px solid DodgerBlue;")
        for (let j = 1; j <= 9; j++)
        {
            tr = document.createElement('tr');
            tr.textContent = `${i} * ${j} = ${i * j}`;
            th.appendChild(tr);
        }
        tbody.appendChild(th);
    }
    document.body.appendChild(table);
}