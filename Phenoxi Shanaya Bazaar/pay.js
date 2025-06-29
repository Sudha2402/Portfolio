// Assuming "productPrice" variable holds the price in rupees



var priceInPaise = productPrice * 100; 



// Initialize Razorpay checkout

var options = {

    "key": "YOUR_RAZORPAY_KEY_ID", // Replace with your Razorpay Key ID

    

    "amount": priceInPaise, 

    "currency": "INR",

    "name": "Your Company Name",

    "description": "Product Description",

    "image": "your_logo_url", 

    "receipt": "order_id_123" 

};



// var rzp = new Razorpay(options);

// rzp.open(); 
