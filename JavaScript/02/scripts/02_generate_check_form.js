window.addEventListener("load", (event) => {
    // document.head.appendChild(html_link("https://fonts.googleapis.com/css2?family=Material+Symbols+Outlined")); //添加google_icon資源(輸入正不正確用)
    generate_form();
  });
function html_link(url)
{
    let link = document.createElement("link");
    link.setAttribute("href", url);
    link.setAttribute("rel", "stylesheet");
    return link;
}

function generate_form()
{
    let form = document.createElement('form');
    let fieldset = document.createElement('fieldset');
    let legend = document.createElement('legend');
    legend.textContent = "Form Check";
    fieldset.appendChild(legend);
    form.appendChild(fieldset);
    let fieldset_name = document.createElement('fieldset');

    let intput_param = {
        id: "input_username",
        label: "姓名：",
        type: "text",
        // tip: "(1.不可留白 2.至少兩個字以上 3.必須全部為中文字)",
        tip: ["不可留白", "至少兩個字以上", "必須全部為中文字"],
        onfocusout: "check_inputfield('input_username')",
        oninput: "check_username()"
    }
    let input_username = create_inputfield(intput_param);

    intput_param = {
        id: "input_password",
        label: "密碼：",
        type: "text",
        // tip: "(1.不可留白 2.至少兩個字以上 3.必須全部為中文字)",
        tip: ["不可留白", "至少六個字以上", "必須包含英數字元", "必須包含特殊字元[!@#$%^&*]"],
        onfocusout: "check_inputfield('input_password')",
        oninput: "check_password()"
    }
    let input_password = create_inputfield(intput_param);

    intput_param = {
        id: "input_date",
        label: "日期：",
        type: "text",
        // tip: "(1.不可留白 2.至少兩個字以上 3.必須全部為中文字)",
        tip: ["格式:西元年/月/日(yyyy/mm/dd)"],
        onfocusout: "check_inputfield('input_date')",
        onchange: "check_date()"
    }
    let input_date = create_inputfield(intput_param);

    fieldset_name.appendChild(input_username);
    fieldset_name.appendChild(input_password);
    fieldset_name.appendChild(input_date);
    fieldset.appendChild(fieldset_name);

    //(1.不可留白 2.至少6個字且必須包含英數字元、特殊字元[!@#$%^&*])

    document.body.appendChild(form);
}

function create_inputfield(intput_param)
{
    let label = document.createElement('label');
    label.textContent = intput_param.label;
    let inputfield = document.createElement('input');
    inputfield.setAttribute("id", intput_param.id);
    inputfield.setAttribute("type", intput_param.type);
    inputfield.setAttribute("oninput", intput_param.oninput);
    inputfield.setAttribute("onfocusout", intput_param.onfocusout);
    inputfield.setAttribute("onchange", intput_param.onchange);
    label.appendChild(inputfield);
    
    let result_symbols = document.createElement('span');
    result_symbols.setAttribute('id', intput_param.id + '_result_symbols');
    label.appendChild(result_symbols);
    let result_message = document.createElement('span');
    result_message.setAttribute('id', intput_param.id + '_result_message');
    label.appendChild(result_message);
    
    let div = document.createElement('div');
    let tip = "";
    if (intput_param.tip.length == 1)
    {
        tip = intput_param.tip[0];
    }
    else
    {
        for (let i = 0; i < intput_param.tip.length; i++)
        {
            tip += `${i+1}.${intput_param.tip[i]}`;
            tip += i + 1 < intput_param.tip.length ? " " : "";
        }
    }
    div.textContent = `(${tip})`;
    label.appendChild(div);
    return  label;
}

function set_result_symbols(span, isPass)
{
    span.setAttribute("class", `material-symbols-outlined ${isPass ? "check_circle" : "check_cancle"}`);
    span.setAttribute("style", `color: ${isPass ? '#78A75A' : '#BB271A'}`);
    span.innerText = isPass ? "check_circle" : "cancel";
    return span;
}

function generate_errorlog()
{
    let newdiv = document.createElement('div');
    newdiv.setAttribute("id", "test1");
    return newdiv;
}

function check_inputfield(id)
{
    let input_field = document.getElementById(id);
    console.log("check_inputfield: "+(id) + ", value: " + input_field.value);
    if (input_field.value.length == 0)
        input_result(id, false, ["不可留白"]);
}

function check_username()
{
    console.log("check_username");
    let input_username = document.getElementById("input_username");
    let value = input_username.value;

    let isPass = true;
    let messages = [];

    if (value.length < 2)
    {
        isPass = false;
        messages.push("至少兩個字以上"); 
    }
    
    for(var i = 0; i < value.length; i++) 
    {
        if(value.charCodeAt(i) < 0x4E00 || value.charCodeAt(i) > 0x9FFF) {
            isPass = false;
            messages.push("輸入非中文，請重新輸入"); 
            break;
        }
    }
    input_result("input_username", isPass, messages);
}

function check_password()
{
    console.log("check_password");
    let input_password = document.getElementById("input_password");
    let value = input_password.value;

    let isPass = true;
    let messages = [];

    if (value.length < 6)
        console.log("至少六個字以上"); 
    
    if (!include_Atoz(value))
    {
        isPass = false;
        messages.push("必須包含英文字元");
    }
    if (!include_1to9(value))
    {
        isPass = false;
        messages.push("必須包含數字字元");
    }
    if (!include_specialsymbol(value))
    {
        isPass = false;
        messages.push("必須包含特殊符號");        
    }
    input_result("input_password", isPass, messages);
}

function check_date()
{
    let check_date = document.getElementById("input_date");
    let value = check_date.value;
    let date = new Date(value).toLocaleDateString();
    console.log("check_date, value: " + date);
    let isPass = true;
    if (date != "Invalid Date" && value.includes('/'))
    {
        let value_split = value.split('/');
        let date_split = value.split('/');
        for (let i = 0; i < value_split.length; i++)
        {
            if (value_split[i] != date_split[i])
            {
                isPass = false;
                input_result("input_date", false, ["請輸入正確日期"]);
            }
        }
        input_result("input_date", true, []);
    }
    else
    {
        isPass = false;
        input_result("input_date", false, ["請照正確格式輸入"]);
    }
}

function include_1to9(string)
{
    for (let i = 0; i < string.length; i++)
        if (string.charCodeAt(i) > 48 && string.charCodeAt(i) < 57)
            return true;
    return false;
}
function include_Atoz(string)
{
    for (let i = 0; i < string.length; i++)
        if (string.charCodeAt(i) > 65 && string.charCodeAt(i) < 122)
            return true;
    return false;
}
function include_specialsymbol(string)
{
    for (let i = 0; i < string.length; i++)
        if ('!@#$%^&*'.includes(string[i]))
            return true;
    return false;
}

function input_result(input_type, isPass, messages)
{
    let result_symbols = document.getElementById(input_type + "_result_symbols");
    set_result_symbols(result_symbols, isPass);
    let result_message = document.getElementById(input_type + "_result_message");
    result_message.innerText = messages.join(", ");
}