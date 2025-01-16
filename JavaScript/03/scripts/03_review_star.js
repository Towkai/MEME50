const star_url = "./images/chngstar.gif"
const star_box = [];
const star_status = [];
const result = {
    default: "您尚未評分",
}

window.addEventListener("load", (event) => {
    generate_starts(5);
    generate_description();
    generate_result();
  });

function generate_starts(num)
{
    let div = document.createElement("div");
    div.setAttribute("id", "star_list");
    div.setAttribute("style", "display:flex");

    for (let i = 0; i < num; i++)
    {
        let img = document.createElement("img");
        star_box.push(img);
        img.setAttribute("src", star_url);
        img.setAttribute("class", "star");
        img.setAttribute("id", "star" + i);
        img.setAttribute("alt", "star" + i);
        star_status.push(1);
        img.setAttribute("style", `filter: grayscale(${star_status[i]});`);
        addlistener(img);
        div.appendChild(img);
    }
    document.body.appendChild(div);
}

function generate_description()
{
    let p = document.createElement("p");
    let i = document.createElement("i");
    i.textContent = "單擊星星可評分，雙擊星星重置";
    p.appendChild(i);
    document.body.appendChild(p);
}

function generate_result()
{
    let p = document.createElement("p");
    p.setAttribute("id", "result");
    p.textContent = result.default;
    document.body.appendChild(p);
}

function addlistener(node)
{
    let listener = {
        click: on_star_onclick,
        dblclick: on_star_ondblclick,
        mouseout: on_star_onmouseout,
        mouseover: on_star_onmouseover,
    }
    for (let event in listener)
        if (listener.hasOwnProperty(event))
            node.addEventListener(event, listener[event]);
}


function on_star_onclick(e) //滑鼠單點
{
    let clicked_index = star_box.indexOf(e.target);
    document.getElementById("result").textContent = `評分為....${clicked_index + 1}`;
    for(let i = 0; i < star_box.length; i++)
    {
        star_status[i] = i <= clicked_index ? 0 : 1;
        star_box[i].setAttribute("style", `filter: grayscale(${star_status[i]})`);
    }
}

function on_star_ondblclick() //滑鼠雙擊
{
    document.getElementById("result").textContent = result.default;
    for(let i = 0; i < star_box.length; i++)
    {
        star_status[i] = 1;
        star_box[i].setAttribute("style", `filter: grayscale(${star_status[i]})`);
    }    
}

function on_star_onmouseover(e) //滑鼠移入
{
    for(let i = 0; i < star_box.length; i++)
        star_box[i].setAttribute("style", `filter: grayscale(${i <= star_box.indexOf(e.target) ? 0 : 1})`);
}

function on_star_onmouseout() //滑鼠移出
{
    for(let i = 0; i < star_box.length; i++)
        star_box[i].setAttribute("style", `filter: grayscale(${star_status[i]})`);
}
