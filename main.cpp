#include <cstdlib>
#include <boost/timer/timer.hpp>
#include <kiss_fft.h>
#include <vector>

int main()
{
    const int fft_size = 512;
    using fft_array = std::vector<kiss_fft_cpx>;

    const kiss_fft_cpx initial_value = {1.0f, 0.0f};
    fft_array input(fft_size, initial_value);
    fft_array output(fft_size);

    kiss_fft_cfg fft_config = kiss_fft_alloc(fft_size, 0, NULL, NULL);
    kiss_fft(fft_config, input.data(), output.data());
    kiss_fft_free(fft_config);
    assert(output[0].r == 512);
	return EXIT_SUCCESS;
}
