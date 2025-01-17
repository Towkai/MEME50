window.addEventListener("load", (event) => {
  generate_carousel();
    onclick_startpause(null);
  });

var img_urls = [
  "images/padoru-0.png",
  "images/padoru-1.png",
  "images/padoru-2.png",
  "images/padoru-3.png"
];

var page = 0;
var clock = null;

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
    let img = document.createElement("img");
    img.setAttribute("id", "carousel" + i);
    img.setAttribute("src", img_urls[i]);
    td.appendChild(img);
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
  table.appendChild(tr);
}

function onclick_startpause(e)
{
  let button_startpause = e == null ? document.getElementById("button_startpause") : e.target;
  if (clock == null)
  {
    button_startpause.textContent = "II";
    clock = setInterval(() => {
      control_carousel(1);
    }, 200);
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