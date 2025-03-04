function onenter_edit(text_id, inputfield_id) {
    document.getElementById(text_id).classList.add('hide');
    document.getElementById(inputfield_id).classList.remove('hide');
}