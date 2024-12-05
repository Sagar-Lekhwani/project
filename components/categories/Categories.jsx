const Categories = () => {
  return (
    <section className="flat-spacing-3 pb_0">
      <div className="container">
        <div className="hover-sw-nav">
          {collectionSlides2.map((slide, index) => (
            <div key={index}>
              <div className="collection-item style-2 hover-img">
                <div className="collection-inner">
                  <Link
                    href={`/shop-collection-sub`}
                    className="collection-image img-style"
                  >
                    <Image
                      className="lazyload"
                      data-src={slide.imgSrc}
                      alt={slide.alt}
                      src={slide.imgSrc}
                      width={600}
                      height={721}
                    />
                  </Link>
                  <div className="collection-content">
                    <Link
                      href={`/shop-collection-sub`}
                      className="tf-btn collection-title hover-icon fs-15"
                    >
                      <span>{slide.title}</span>
                      <i className="icon icon-arrow1-top-left" />
                    </Link>
                  </div>
                </div>
              </div>
            </div>
          ))}
          <div className="nav-sw nav-next-slider nav-next-collection box-icon w_46 round snbp306">
            <span className="icon icon-arrow-left" />
          </div>
          <div className="nav-sw nav-prev-slider nav-prev-collection box-icon w_46 round snbn306">
            <span className="icon icon-arrow-right" />
          </div>
          <div className="sw-dots style-2 sw-pagination-collection justify-content-center spd306" />
        </div>
      </div>
    </section>
  );
};

export default Categories;
