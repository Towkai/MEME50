window.addEventListener("load", (event) => {
  generate_carousel();
    onclick_startpause(null);
  });

var img_urls = [
  { url: "images/padoru-0.png", link:"https://youtu.be/dQ_d_VKrFgM"},
  { url: "images/padoru-1.png", link:"https://youtu.be/ZtOykzpYJXk?t=1m20s"},
  { url: "images/padoru-2.png", link:"https://youtu.be/KoyGsLyUjJE?t=3m45s"},
  { url: "images/padoru-3.png", link:"https://youtu.be/dQw4w9WgXcQ"},
];

var page = 0;
var clock = null;
var speed_default = 200; //毫秒
var speed = 200;

function generate_carousel()
{
  let table = document.createElement("table");
  table.setAttribute("border", 1)
  table.setAttribute("style", "border-style:ridge;border-collapse: collapse;text-align:left;width:max-content;")
  let caption = document.createElement('caption');
  caption.textContent = "ads carousel";
  table.appendChild(caption);

  create_imgs(table);
  create_controlbar(table);
  
  document.body.appendChild(table);
}

function create_imgs(table)
{
  let tr = document.createElement("tr");
  let td = document.createElement('td');
  for (let i = 0; i < img_urls.length; i++)
  {
    let a = document.createElement("a");
    a.setAttribute("href", img_urls[i].link);
    let img = document.createElement("img");
    img.setAttribute("id", "carousel" + i);
    img.setAttribute("src", img_urls[i].url);
    a.appendChild(img);
    td.appendChild(a);
  }
  tr.appendChild(td);
  table.appendChild(tr);
}

function control_carousel(e)
{
  page = (page + e) % img_urls.length;
  if (page < 0)
    page = img_urls.length - 1;
  for (let i = 0; i < img_urls.length; i++)
  {
    let img = document.getElementById("carousel" + i);
    img.setAttribute("style", `display: ${i == page ? '' : 'none'}`);
  }
}

function create_controlbar(table)
{
  let tr = document.createElement("tr");
  tr.setAttribute("style", "text-align:center; display: flex; justify-content: space-around;");
  let last = document.createElement('button');
  let startpause = document.createElement('button');
  let next = document.createElement('button');
  startpause.setAttribute("id", "button_startpause");
  last.setAttribute("style", "width: 50px");
  startpause.setAttribute("style", "width: 50px");
  next.setAttribute("style", "width: 50px");
  last.textContent = '⮪';
  startpause.textContent = '▶';
  next.textContent = '⮫';
  last.addEventListener("click", e => {pause_carousel(null); control_carousel(-1);});
  startpause.addEventListener("click", onclick_startpause);
  next.addEventListener("click", e => {pause_carousel(null); control_carousel(1);});
  tr.appendChild(last);
  tr.appendChild(startpause);
  tr.appendChild(next);

  let speed = create_speedbar();
  tr.appendChild(speed);

  table.appendChild(tr);
}

function create_speedbar()
{
  let select = document.createElement("select");
  select.addEventListener("change", on_speed_change);
  select.setAttribute("id", "speed");
  select.setAttribute("name", "speed");
  select.setAttribute("aria-label", "speed");
  let options = create_opions([0.25, 0.5, 1.0, 1.25, 1.5, 1.75, 2.0, 3.0, 4.0, 5.0, 6.0]);
  for (let option of options)
    select.appendChild(option);
  return select;
}

function on_speed_change(e) {
  console.log(1/e.target.value);
  speed = speed_default * (1 / e.target.value);
  clearInterval(clock);
  clock = setInterval(() => {
    control_carousel(1);
  }, speed);
}

function create_opions(values)
{
    let options = [];
    for (let i = 0; i < values.length; i++)
    {
      let option = document.createElement("option");
      option.setAttribute("value", values[i]);
      if (values[i] == 1)
        option.setAttribute("selected","");
      option.textContent = 'x' + values[i].toFixed(2);
      options.push(option);
    }
    return options;
}

function onclick_startpause(e)
{
  let button_startpause = e == null ? document.getElementById("button_startpause") : e.target;
  if (clock == null)
  {
    button_startpause.textContent = "II";
    clock = setInterval(() => {
      control_carousel(1);
    }, speed);
  }
  else
  {
    pause_carousel(button_startpause);
  }
}

function pause_carousel(e)
{
  let button_startpause = e ?? document.getElementById("button_startpause");
  button_startpause.textContent = "▶";
  clearInterval(clock);
  clock = null;
}