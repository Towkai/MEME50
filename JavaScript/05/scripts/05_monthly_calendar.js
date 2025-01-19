window.addEventListener("load", (event) => {
  generate_container();
});

var row_height = 50;

function generate_container()
{
    let div = document.createElement("div");
    div.style["display"] = "flex";
    div.style["width"] = "max-content";
    let table = create_calendar();
    div.appendChild(table);
    document.body.appendChild(div);
}

function create_calendar()
{
  let calendar = create_table();
  let tr = document.createElement("tr");
  let th = document.createElement("th");
  th.colSpan = 8;
  th.height = row_height;
  tr.appendChild(th);
  calendar.appendChild(tr);
  
  tr = document.createElement("tr");
  for (let i = -1; i < 7; i++)  //-1留給標題
  {
    th = document.createElement("th");
    th.height = row_height;
    th.textContent = convert_weekname(i);
    tr.appendChild(th);
    calendar.appendChild(tr);  
  }

  for (let i = 0; i < 5; i++)    //一個月最多有5週
  {
    tr = document.createElement("tr");
    tr.className = "weeks";
    tr.id = "week" + i;
    for (let j = -1; j < 7; j++)  //-1留給標題
    {
      let td = document.createElement("td");
      td.id = "day" + j;
      td.width = row_height;
      td.height = row_height;
      if (j == -1)
        td.textContent = "week." + (i + 1);
      tr.appendChild(td);
    }
    calendar.appendChild(tr);
  }
  return calendar;
}

function create_table()
{
    let table = document.createElement("table");
    table.setAttribute("border", 1);
    table.style["display"] = "inline-table";
    table.style["border-collapse"] = "collapse";
    table.style["margin-right"] = "50px";
    table.style["border-color"] = "black";

    return table;
}

function convert_weekname(n)
{
  switch (n)
  {
    case 0: return "SUN";
    case 1: return "MON";
    case 2: return "TUE";
    case 3: return "WED";
    case 4: return "THU";
    case 5: return "FRI";
    case 6: return "SAT";
    default: '';
  }
}