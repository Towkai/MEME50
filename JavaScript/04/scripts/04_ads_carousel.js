window.addEventListener("load", (event) => {
    document.head.appendChild(html_link("https://fonts.googleapis.com/css2?family=Material+Symbols+Outlined:FILL@0..1"));
    generate_carousel();
    onclick_startpause(null);
  });

var img_urls = [
  { url: "https://raw.githubusercontent.com/Towkai/MEME50/refs/heads/main/JavaScript/04/images/padoru-2.png", link:"https://youtu.be/dQ_d_VKrFgM"},
  { url: "https://raw.githubusercontent.com/Towkai/MEME50/refs/heads/main/JavaScript/04/images/padoru-1.png", link:"https://youtu.be/ZtOykzpYJXk?t=1m20s"},
  { url: "https://raw.githubusercontent.com/Towkai/MEME50/refs/heads/main/JavaScript/04/images/padoru-0.png", link:"https://youtu.be/KoyGsLyUjJE?t=3m45s"},
  { url: "https://raw.githubusercontent.com/Towkai/MEME50/refs/heads/main/JavaScript/04/images/padoru-3.png", link:"https://youtu.be/dQw4w9WgXcQ"},
];

var page = 0;
var clock = null;
var speed_default = 200; //毫秒
var speed = 200;
var button_width = "50px"

function html_link(url)
{
  let link = document.createElement("link");
  link.setAttribute("href", url);
  link.setAttribute("rel", "stylesheet");
  return link;
}

function char_unselect(n)
{
  // return String.fromCharCode(0x2460 + n);
  let button = document.getElementById("progress_button" + n);
  if (button != null)
    button.setAttribute("style", `width: ${button_width}; font-variation-settings: 'FILL' 0;`);
  let icon = document.getElementById("progress_icon" + n);
  if (icon != null)
    icon.textContent = "counter_" + (n + 1);
}
function char_selected(n)
{
  // return String.fromCharCode(0x2776 + n);
  // return String.fromCharCode(0x24F5 + n);
  let button = document.getElementById("progress_button" + n);
  if (button != null)
    button.setAttribute("style", `width: ${button_width}; font-variation-settings: 'FILL' 1;`);
  // let icon = document.getElementById("progress_icon" + n);
  // switch (n + 1)
  // {
  //   case 1:
  //     icon.textContent = "looks_one";
  //     break;
  //   case 2:
  //     icon.textContent = "looks_two";
  //     break;
  //   default:
  //     icon.textContent = "looks_" + (n + 1);
  //     break;
  // }
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
    char_unselect(i);
    if (i == page)
      char_selected(i);
    // let button = document.getElementById("progress_icon" + i);
    // button.textContent = i == page ? char_selected(i) : char_unselect(i);
  }
}

function create_progressbar()
{
  let tr = document.createElement("tr");
  tr.setAttribute("style", "text-align:center; display: flex; justify-content: space-around;margin:0px 25px 0px 25px;");
  for (let i = 0; i < img_urls.length; i++)
  {
    let button = document.createElement("button");
    button.setAttribute("id", "progress_button" + i);
    // button.setAttribute("style", `width: ${button_width}`);
    button.addEventListener("click", (e) => {pause_carousel(null);set_carousel(i)});
    button.value = i;
    button.appendChild(create_google_symbols_outlined("progress_icon" + i), char_unselect(i));
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
  let start = document.createElement('button');
  let anti = document.createElement('button');
  let next = document.createElement('button');
  last.setAttribute("style", `width: ${button_width}`);
  startpause.setAttribute("style", `width: ${button_width}`);
  start.setAttribute("style", `width: ${button_width}`);
  anti.setAttribute("style", `width: ${button_width}`);
  next.setAttribute("style", `width: ${button_width}`);
  last.appendChild(create_google_symbols_outlined(null, "arrow_back"));
  startpause.appendChild(create_google_symbols_outlined("icon_startpause", null));
  start.appendChild(create_google_symbols_outlined(null, "start"));
  anti.appendChild(create_google_symbols_outlined(null, "reply"));
  next.appendChild(create_google_symbols_outlined(null, "arrow_forward"));
  last.addEventListener("click", e => {pause_carousel(null); control_carousel(-1);});
  startpause.addEventListener("click", onclick_startpause);
  start.addEventListener("click", e => {start_carousel(null); });
  anti.addEventListener("click", e => {anti_carousel(null); });
  next.addEventListener("click", e => {pause_carousel(null); control_carousel(1);});
  last.setAttribute("title", "上一張");
  startpause.setAttribute("title", "開始/暫停");
  start.setAttribute("title", "向前播放");
  anti.setAttribute("title", "向後倒播");
  next.setAttribute("title", "下一張");
  tr.appendChild(last);
  tr.appendChild(startpause);
  tr.appendChild(start);
  tr.appendChild(anti);
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
  let icon_startpause = document.getElementById("icon_startpause");
  if (clock == null)
  {
    set_google_symbols_outlined(icon_startpause, "Pause");
    clock = setInterval(() => {
      control_carousel(1);
    }, speed);
  }
  else
  {
    pause_carousel(icon_startpause);
  }
}

function pause_carousel(e)
{
  let icon_startpause = document.getElementById("icon_startpause");
  set_google_symbols_outlined(icon_startpause, "play_arrow")
  clearInterval(clock);
  clock = null;
}
function start_carousel(e)
{
  let icon_startpause = document.getElementById("icon_startpause");
  if (clock != null)
    pause_carousel(icon_startpause);
  set_google_symbols_outlined(icon_startpause, "Pause");
  clock = setInterval(() => {
    control_carousel(1);
  }, speed);
}

function anti_carousel(e)
{
  let icon_startpause = document.getElementById("icon_startpause");
  if (clock != null)
    pause_carousel(icon_startpause);
  set_google_symbols_outlined(icon_startpause, "Pause");
  clock = setInterval(() => {
    control_carousel(-1);
  }, speed);
}

function create_google_symbols_outlined(id, icon)
{
  let span = document.createElement("span");
  span.setAttribute("class", "material-symbols-outlined");
  span.setAttribute("style", "line-height: 100%");
  if (id)
    span.setAttribute("id", id);
  if (icon)
    span.textContent = icon;
  return span;
}

function set_google_symbols_outlined(span, icon)
{
  span.textContent = icon;
}