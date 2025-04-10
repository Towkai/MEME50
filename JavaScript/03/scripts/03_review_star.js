const star_url = "https://raw.githubusercontent.com/Towkai/MEME50/refs/heads/main/JavaScript/03/images/chngstar.gif"
const star_box = [];
const star_status = []; //灰階程度，1 = 全黑白，0 = 全彩
const result = {
    title: "單擊星星可評分，雙擊星星重置",
    text:"您尚未評分",
    default: "您尚未評分",
}

function str_review_result(num)
{
    return `評分為....${num}`;
}

window.addEventListener("load", (event) => {
    generate_starts(5);
    generate_description();
    generate_result();
  });

function generate_starts(num)
{
    let div = document.createElement("div");
    div.id = "star_list";
    div.style["display"] = "flex";

    for (let i = 0; i < num; i++)
    {
        let img = document.createElement("img");
        star_box.push(img);
        img.className = "star";
        img.id = "star" + i;
        img.setAttribute("src", star_url);
        img.setAttribute("alt", "star" + i);
        star_status.push(1);
        img.style["filter"] = `grayscale(${star_status[i]}`;
        addlistener(img);
        div.appendChild(img);
    }
    document.body.appendChild(div);
}

function generate_description()
{
    let p = document.createElement("p");
    let i = document.createElement("i");
    i.textContent = result.title;
    p.appendChild(i);
    document.body.appendChild(p);
}

function generate_result()
{
    let p = document.createElement("p");
    p.id = "result";
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
    result.text = str_review_result(clicked_index + 1);
    document.getElementById("result").textContent = result.text;
    for(let i = 0; i < star_box.length; i++)
    {
        star_status[i] = i <= clicked_index ? 0 : 1;
        star_box[i].style["filter"] = `grayscale(${star_status[i]})`;
    }
}

function on_star_ondblclick() //滑鼠雙擊
{
    result.text = result.default;
    document.getElementById("result").textContent = result.default;
    for(let i = 0; i < star_box.length; i++)
    {
        star_status[i] = 1;
        star_box[i].style["filter"] = `grayscale(${star_status[i]})`;
    }    
}

function on_star_onmouseover(e) //滑鼠移入
{
    document.getElementById("result").textContent = str_review_result(star_box.indexOf(e.target) + 1);
    for(let i = 0; i < star_box.length; i++)
        star_box[i].style["filter"] = `grayscale(${i <= star_box.indexOf(e.target) ? 0 : 1})`;
}

function on_star_onmouseout() //滑鼠移出
{
    document.getElementById("result").textContent = result.text;
    for(let i = 0; i < star_box.length; i++)
        star_box[i].style["filter"] = `grayscale(${star_status[i]})`;
}
