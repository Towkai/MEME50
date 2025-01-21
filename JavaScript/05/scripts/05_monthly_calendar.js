window.addEventListener("load", (event) => {
  generate_calendar_container();
});

var row_height = 50;
var year_min = 2010;
var year_max = 2030;
var isleap = false;
var str_idle = "請選擇日期";
function generate_calendar_container() {
  let div = document.createElement("div");
  div.style["display"] = "flex";
  div.style["width"] = "max-content";
  let table = create_calendar();
  div.appendChild(table);
  let p = document.createElement("p");
  p.id = "result";
  p.textContent = "請選擇日期";
  div.appendChild(p);
  document.body.appendChild(div);
}

function create_calendar() {
  let calendar = create_table();
  let tr = create_select_row();
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
      let cell = document.createElement(j == -1 ? "th" : "td");
      cell.classList.add(j == -1 ? "day_title" : "day");
      cell.classList.add("day" + j);
      cell.id = `day${i}-${j}`;
      cell.width = row_height;
      cell.height = row_height;
      if (j == -1)
        cell.textContent = "week." + (i + 1);
      tr.appendChild(cell);
    }
    calendar.appendChild(tr);
  }
  return calendar;
}

function create_select_row() {
  let tr = document.createElement("tr");
  let th = document.createElement("th");
  th.colSpan = 8;
  th.height = row_height;

  let select_year_container = create_dropdown_container("year-select", "/", get_year_options(), on_year_change);
  let select_month_container = create_dropdown_container("month-select", "/", get_month_options(), on_month_change);
  let select_day_container = create_dropdown_container("day-select", "", [-1], on_day_change);
  th.appendChild(select_year_container);
  th.appendChild(select_month_container);
  th.appendChild(select_day_container);
  tr.appendChild(th);
  return tr;
}

function create_dropdown_container(id, name, options, callback) {
  let container = document.createElement("div");
  container.style["display"] = "inline-block";
  // container.style["margin"] = "0px 5px 0px 5px";
  let select = document.createElement("select");
  select.id = id;
  select.addEventListener("change", callback);


  set_options(select, options);

  container.appendChild(select);
  let label = document.createElement("label");
  label.setAttribute("for", id);
  label.textContent = name;
  container.appendChild(label);
  return container;
}

function set_options(select, options) {
  select.innerHTML = "";
  for (let i = 0; i < options.length; i++) {
    let option = document.createElement("option");
    option.hidden = false;
    option.value = options[i];
    option.textContent = options[i] == -1 ? "--select--" : options[i];
    select.appendChild(option);
  }
}

function get_year_options() {
  let options = [];
  options.push(-1);
  for (let i = year_min; i <= year_max; i++)
    options.push(i);
  return options;
}

function get_month_options() {
  let options = [];
  options.push(-1);
  for (let i = 1; i <= 12; i++)
    options.push(i);
  return options;
}
function set_day_options(month_value) {
  let month_day = get_month_day(month_value);
  let options = [-1];
  for (let i = 1; i <= month_day; i++)
    options.push(i);
  set_options(document.getElementById("day-select"), options);
}
function on_year_change(e) {
  let month_value = document.getElementById("month-select").value;
  if (month_value == -1)
    return;
  isleap = e.target.value % 4 == 0;
  document.getElementById("result").textContent = str_idle;
  set_calendar_content(e.target.value, month_value);
  set_day_options(month_value);
}
function on_month_change(e) {
  let year_value = document.getElementById("year-select").value;
  if (year_value == -1)
    return;
  document.getElementById("result").textContent = str_idle;
  set_day_options(e.target.value);
  set_calendar_content(year_value, e.target.value);
}
function get_month_day(month) {
  switch (parseInt(month)) {
    case 1: return 31;
    case 2: return isleap ? 29 : 28;
    case 3: return 31;
    case 4: return 30;
    case 5: return 31;
    case 6: return 30;
    case 7: return 31;
    case 8: return 31;
    case 9: return 30;
    case 10: return 31;
    case 11: return 30;
    case 12: return 31;
    default: return -1;
  }
}

function on_day_change(e) {
  let year_value = parseInt( document.getElementById("year-select").value);
  let month_value = parseInt(document.getElementById("month-select").value);
  let day_value = parseInt(e.target.value);
  let information = document.getElementById("result");
  information.innerHTML = `目前選擇的是 ${year_value} 年 ${month_value} 月 ${day_value} 日<br>${get_weekday_cht(year_value, month_value, day_value)}`;
  
  let startday = get_weekday(year_value, month_value, 1);
  let day_id = `day${Math.floor((startday + day_value - 1) / 7)}-${(startday + day_value - 1) % 7}`;
  let days = document.getElementsByClassName("day");
  for (let i = 0; i < days.length; i++)
    days[i].style["background-color"] = days[i].id == day_id ? "burlywood" : "white";
}

function create_month_option() {

}

function create_day_option() {

}

function create_table() {
  let table = document.createElement("table");
  table.setAttribute("border", 1);
  table.style["display"] = "inline-table";
  table.style["border-collapse"] = "collapse";
  table.style["margin-right"] = "50px";
  table.style["border-color"] = "black";

  return table;
}

function convert_weekname(n) {
  switch (n) {
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

function get_weekday(y, m, d) {
  return new Date(`${y}-${m}-${d}`).getDay();
}
function get_weekday_cht(y, m, d) {
  let day = get_weekday(y, m, d);
  switch (day)
  {
    case 0: return "星期日";
    case 1: return "星期一";
    case 2: return "星期二";
    case 3: return "星期三";
    case 4: return "星期四";
    case 5: return "星期五";
    case 6: return "星期六";
  }
}

function set_calendar_content(y, m) {
  let start = get_weekday(y, m, 1);
  let monthday = get_month_day(m);
  let days = document.getElementsByClassName("day");
  for (let i = 0; i < days.length; i++)  //總共有35格
  {
    days[i].style["background-color"] = "white";
    if (i >= start && i < monthday + start)
      days[i].textContent = i - start + 1;
    else
      days[i].textContent = "";
  }
}