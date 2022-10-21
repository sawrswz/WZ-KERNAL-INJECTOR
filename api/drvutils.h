#pragma once

void start_driver()
{
	driver().handle_driver();

	if (!driver().is_loaded())
	{
		cout << xor_a("Driver Not Loaded!\nLoading Driver Now...") << endl;
		mmap_driver();
	}

	driver().handle_driver();
	driver().is_loaded() ? cout << xor_a("Loaded Driver!") << endl : cout << xor_a("Error While Loading Driver!") << endl;
}

