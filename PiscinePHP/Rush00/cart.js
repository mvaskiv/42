var cart = document.getElementById("cart");
var addToCartButtons = document.getElementsByClassName("shop-add-to-cart-button");
var orderDataElem = document.getElementById("order-data-elem");
var orderPriceElem = document.getElementById("order-price");
var shopProductFilter = document.getElementById("shop-product-filter");
var cartData = {};
var totalPrice = 0;

function getMinus(productName) {
	var minus = document.createElement("button");
	
	minus.innerHTML = "-";
	minus.addEventListener("click", function() {
		if (minus.previousSibling.innerHTML > 1) {
			totalPrice = totalPrice - parseInt(cartData[productName][0]);
			cartData[productName][1] -= 1;
			rerenderCart();
		}
	});
	return minus;
}

function getPlus(productName) {
	var plus = document.createElement("button");
	
	plus.innerHTML = "+";
	plus.addEventListener("click", function() {
		totalPrice = totalPrice + parseInt(cartData[productName][0]);
		cartData[productName][1] += 1;
		rerenderCart();
	});
	return plus;
}

function getCross(productName, price) {
	var cross = document.createElement("button");

	cross.innerHTML = "&#215;";
	cross.addEventListener("click", function() {
		delete cartData[productName];
		totalPrice -= price;
		rerenderCart();
	});
	return cross;
}

function rerenderCart() {
	var cart = document.getElementById("cart");
	var productNames = Object.keys(cartData);
	var priceEl = document.createElement("div");

	while (cart.firstChild) {
		cart.removeChild(cart.firstChild);
	}
	priceEl.innerHTML = "Total price: " + totalPrice;
	cart.appendChild(priceEl);
	productNames.forEach(function(productName) {
		var newProductEl = document.createElement("div");
		var newProductElName = document.createElement("span");
		var newProductElPrice = document.createElement("span");
		var newProductElAmount = document.createElement("span");
		
		newProductElName.innerHTML = productName;
		newProductElPrice.innerHTML = "$" + cartData[productName][0];
		newProductElAmount.innerHTML = cartData[productName][1];
		newProductEl.appendChild(newProductElName);
		newProductEl.appendChild(newProductElPrice);
		newProductEl.appendChild(newProductElAmount);
		newProductEl.appendChild(getMinus(productName));
		newProductEl.appendChild(getPlus(productName));
		newProductEl.appendChild(getCross(productName, cartData[productName][0] * cartData[productName][1]));
		cart.appendChild(newProductEl);
	});
}

Array.from(addToCartButtons).forEach(function(button) {
	button.addEventListener("click", function() {
		var productName = button.parentNode.children[1].children[0].innerHTML;
		var productPrice = button.parentNode.children[1].children[1].innerHTML.substring(1);
		
		if (cartData[productName] === undefined) {
			cartData[productName] = [productPrice, 1];
		}
		else {
			cartData[productName] = [productPrice, parseInt(cartData[productName][1]) + 1];
		}
		totalPrice += parseFloat(productPrice);
		rerenderCart();
	});
});

document.getElementById("submit-order").addEventListener("click", function() {
	var newOrderData = {};

	for (var key in cartData) {
		newOrderData[key] = cartData[key][1];
	}
	orderDataElem.value = JSON.stringify(newOrderData);
	orderPriceElem.value = totalPrice;
});
