window.addEventListener("load", (event) => {
    generate_carousel();
    onclick_startpause(null);
  });

var img_urls = [
  { url: "https://raw.githubusercontent.com/Towkai/MEME50/refs/heads/main/JavaScript/04/images/padoru-0.png", link:"https://youtu.be/dQ_d_VKrFgM"},
  { url: "https://raw.githubusercontent.com/Towkai/MEME50/refs/heads/main/JavaScript/04/images/padoru-1.png", link:"https://youtu.be/ZtOykzpYJXk?t=1m20s"},
  { url: "https://raw.githubusercontent.com/Towkai/MEME50/refs/heads/main/JavaScript/04/images/padoru-2.png", link:"https://youtu.be/KoyGsLyUjJE?t=3m45s"},
  { url: "https://raw.githubusercontent.com/Towkai/MEME50/refs/heads/main/JavaScript/04/images/padoru-3.png", link:"https://youtu.be/dQw4w9WgXcQ"},
];

var page = 0;
var clock = null;
var speed_default = 200; //毫秒
var speed = 200;
var button_width = "50px"

function char_unselect(n)
{
  return String.fromCharCode(0x2460 + n);
}
function char_selected(n)
{
  // return String.fromCharCode(0x2776 + n);
  return String.fromCharCode(0x24F5 + n);
}

function generate_carousel()
{
  let table = document.createElement("table");
  table.setAttribute("border", 1)
  table.setAttribute("style", "border-style:ridge;border-collapse: collapse;text-align:left;width:max-content;")
  let caption = document.createElement('caption');
  caption.textContent = "ads carousel";
  table.appendChild(caption);

  table.appendChild(create_imgs());
  table.appendChild(create_progressbar());
  table.appendChild(create_controlbar());
  
  document.body.appendChild(table);
}

function create_imgs()
{
  let tr = document.createElement("tr");
  let td = document.createElement('td');
  for (let i = 0; i < img_urls.length; i++)
  {
    let a = document.createElement("a");
    a.setAttribute("href", img_urls[i].link);
    a.setAttribute("target", "_blank");
    let img = document.createElement("img");
    img.setAttribute("id", "carousel" + i);
    img.setAttribute("src", img_urls[i].url);
    a.appendChild(img);
    td.appendChild(a);
  }
  tr.appendChild(td);
  return tr;
}

function control_carousel(e)
{
  page = (page + e) % img_urls.length;
  if (page < 0)
    page = img_urls.length - 1;
  set_carousel(page);
}
function set_carousel(e)
{
  page = e;
  for (let i = 0; i < img_urls.length; i++)
  {
    let img = document.getElementById("carousel" + i);
    img.setAttribute("style", `display: ${i == page ? '' : 'none'}`);
    let button = document.getElementById("progress" + i);
    button.textContent = i == page ? char_selected(i) : char_unselect(i);
  }
}

function create_progressbar()
{
  let tr = document.createElement("tr");
  tr.setAttribute("style", "text-align:center; display: flex; justify-content: space-around;margin:0px 25px 0px 25px;");
  for (let i = 0; i < img_urls.length; i++)
  {
    let button = document.createElement("button");
    button.setAttribute("style", `width: ${button_width}`)
    button.setAttribute("id", "progress" + i);
    button.addEventListener("click", (e) => {pause_carousel(null);set_carousel(i)});
    button.value = i;
    button.textContent = char_unselect(i + 1);
    tr.appendChild(button);
  }
  return tr;
}

function create_controlbar()
{
  let tr = document.createElement("tr");
  tr.setAttribute("style", "text-align:center; display: flex; justify-content: space-around;margin:0px 25px 0px 25px;");
  let last = document.createElement('button');
  let startpause = document.createElement('button');
  let next = document.createElement('button');
  startpause.setAttribute("id", "button_startpause");
  last.setAttribute("style", `width: ${button_width}`);
  startpause.setAttribute("style", `width: ${button_width}`);
  next.setAttribute("style", `width: ${button_width}`);
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
  return tr;
}

function create_speedbar()
{
  let select = document.createElement("select");
  select.addEventListener("change", on_speed_change);
  select.setAttribute("id", "speed");
  select.setAttribute("name", "speed");
  select.setAttribute("aria-label", "speed");
  select.setAttribute("style", `width: ${button_width}`);
  let speed_list = [];
  for (let i = 0.5; i <= 6; i += 0.5)
  {
    speed_list.push(i);
  }
  let options = create_opions(speed_list);
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
      option.textContent = 'x' + values[i].toFixed(1);
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