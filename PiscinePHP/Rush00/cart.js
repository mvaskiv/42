var cart = document.getElementById("cart");
var addToCartButtons = document.getElementsByClassName("shop-add-to-cart-button");
var orderDataElem = document.getElementById("order-data-elem");
var cartData = {};

function rerenderCart() {
	console.log("here");
	var cart = document.getElementById("cart");
	var productNames = Object.keys(cartData);

	while (cart.firstChild) {
		cart.removeChild(cart.firstChild);
	}
	productNames.forEach(function(productName) {
		var newProductEl = document.createElement("div");
		
		newProductEl.innerHTML = productName + " " + cartData[productName];
		cart.appendChild(newProductEl);
	});
}

Array.from(addToCartButtons).forEach(function(button) {
	button.addEventListener("click", function() {
		var productName = button.previousSibling.previousSibling.innerHTML;
		
		if (cartData[productName] === undefined)
			cartData[productName] = 1;
		else
			cartData[productName] = cartData[productName] + 1;
		rerenderCart();
		orderDataElem.value = JSON.stringify(cartData);
	});
});
