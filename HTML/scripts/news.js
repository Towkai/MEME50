function throttle(func, limit) {
    let lastFunc;
    let lastRan;

    return function (...args) {
        const context = this;

        if (!lastRan) {
            func.apply(context, args);
            lastRan = Date.now();
        } else {
            clearTimeout(lastFunc);
            lastFunc = setTimeout(function () {
                if (Date.now() - lastRan >= limit) {
                    func.apply(context, args);
                    lastRan = Date.now();
                }
            }, limit - (Date.now() - lastRan));
        }
    };
}

function ScrollToTop() {
    let x = window.scrollX;
    let y = window.scrollY;
    console.log(x, y);
    let interval = setInterval(function () {
        if (y > 0) {
            window.scrollTo(x, y);
            y -= 50;
        } else {
            window.scrollTo(x, 0);
            clearInterval(interval);
        }
    }, 5);
}

function AddScrollListener() {
    let scrollButton = document.getElementById("TopButton");
    if (window.scrollY > 0)
        scrollButton.style.display = "block";
    window.addEventListener("scroll", throttle(ScrollEvent, 200));
}

WindowPosY = 0;
function ScrollEvent() {
    console.log("window.scrollY = " + window.scrollY);
    let scrollButton = document.getElementById("TopButton");
    if (window.scrollY > 0) {
        let deltaY = window.scrollY - WindowPosY;
        // const offsetY = window.scrollY + window.innerHeight - scrollButton.offsetHeight - 20; 
        // scrollButton.style.transform = `translateY(${offsetY}px)`; 
        scrollButton.style.display = "block";
    } else {
        WindowPosY = 0;
        scrollButton.style.display = "none";
    }
}
