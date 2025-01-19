window.addEventListener("load", (event) => {
    generate_multiplication_table();
  });

function generate_multiplication_table()
{
    let table = document.createElement('table');
    // table.setAttribute("border", "1");
    table.setAttribute("bgcolor", "Aqua");
    table.style["color"] = "red";
    table.style["border-style"] = "ridge";
    table.style["border"] = "5px solid DodgerBlue";
    table.style["border-collapse"] = "collapse";
    table.style["text-align"] = "left";
    table.style["width"] = "max-content";
    let caption = document.createElement('caption');
    caption.style["color"] = "black";
    caption.textContent = "九九乘法表";
    let tbody = document.createElement('tbody');
    table.appendChild(caption);
    table.appendChild(tbody);
    
    for (let i = 1; i <= 9; i++)
    {
        let th = document.createElement('th');
        th.style["border"] = "5px solid DodgerBlue";
        for (let j = 1; j <= 9; j++)
        {
            tr = document.createElement('tr');
            td = document.createElement('td');
            td.textContent = `${i} * ${j} = ${i * j}`;
            tr.appendChild(td);
            th.appendChild(tr);
        }
        tbody.appendChild(th);
    }
    document.body.appendChild(table);
}